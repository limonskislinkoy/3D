#version 460

const int MAX_OBJ=21;
const int LEN_OBJ=15;

const int MAX_REFLECT=8;
const int COUNT_RAYS=2;

const int LEN_FOR_COLOR=4;
float MAS_COLORS[MAX_REFLECT*LEN_FOR_COLOR];

float MAS_RAYS_COLORS[LEN_FOR_COLOR*COUNT_RAYS];

const int COUNT_LIGHTS=2;
const int ID_LIGHTS[COUNT_LIGHTS] = {9,10};
const float STR_LIGHTS[COUNT_LIGHTS] = {1,0.1};
const vec4 dark=vec4(0.0,0.0,0.0,0.0);
const vec4 nebo=vec4(52.0/255.0,192.0/255.0,235.0/255.0,1.0);




const float pi=3.1415;

vec2 random_num = vec2(0.54,0.12);

uniform vec2 resolution;
uniform vec3 player_pos;
uniform vec2 player_dir_angle;
uniform float time;
uniform float objects[MAX_OBJ*LEN_OBJ];

out vec4 colorout;



void fill_colors(){
	for(int i =0; i <MAX_REFLECT*LEN_FOR_COLOR*COUNT_RAYS; i++ ){
		MAS_COLORS[i]=-1;
	}
}

vec4 MIX_colors(){

	vec4 res=vec4(1.0);
	int col_colors=1;
	for(int i =0; i <MAX_REFLECT*LEN_FOR_COLOR; i+=LEN_FOR_COLOR ){
		if (MAS_COLORS[i+3]!=-1){
			col_colors+=1;
			break;
		}
	}


	for(int i =0; i <col_colors; i++ ){
			res.xyz= mix(res.xyz,vec3(MAS_COLORS[i*LEN_FOR_COLOR],MAS_COLORS[i*LEN_FOR_COLOR+1],MAS_COLORS[i*LEN_FOR_COLOR+2]),0.5);
	}
	return res;

}

vec4 MIX_ray_colors(){
	vec4 res=vec4(vec3(MAS_RAYS_COLORS[0],MAS_RAYS_COLORS[0+1],MAS_RAYS_COLORS[0+2]),1.0);
	int col_colors=COUNT_RAYS;
	for(int i =0; i <col_colors; i++ ){
			res.xyz= mix(res.xyz,vec3(MAS_RAYS_COLORS[i*LEN_FOR_COLOR],MAS_RAYS_COLORS[i*LEN_FOR_COLOR+1],MAS_RAYS_COLORS[i*LEN_FOR_COLOR+2]),0.5);
	}

	return res;
}


float random(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}



vec3 triIntersect( in vec3 ro, in vec3 rd, in vec3 v0, in vec3 v1, in vec3 v2 )
{
    vec3 v1v0 = v1 - v0;
    vec3 v2v0 = v2 - v0;
    vec3 rov0 = ro - v0;
    vec3  n = cross( v1v0, v2v0 );
    vec3  q = cross( rov0, rd );
    float d = 1.0/dot( rd, n );
    float u = d*dot( -q, v2v0 );
    float v = d*dot(  q, v1v0 );
    float t = d*dot( -n, rov0 );
    if( u<0.0 || v<0.0 || (u+v)>1.0 ) t = -1.0;
    return vec3( t, u, v );
}

vec2 sphIntersect( in vec3 ro, in vec3 rd, in vec3 ce, float ra )
{
    vec3 oc = ro - ce;
    float b = dot( oc, rd );
    float c = dot( oc, oc ) - ra*ra;
    float h = b*b - c;
    if( h<0.0 ) return vec2(-1.0); // no intersection
    h = sqrt( h );
    return vec2( -b-h, -b+h );
}


mat2 rotate(float a) {
	float s = sin(a);
	float c = cos(a);
	return mat2(c, -s, s, c);
}

vec2 Ray_intersect(in vec3 ro, in vec3 rd, in int id_from){
	int id=-1; // NO intersect
	float min_lenght=9999999;
	for(int i=0; i<MAX_OBJ;i++){
		if(i==id_from){continue;}
		else{
	
			if (objects[LEN_OBJ * i ]==1.0 ){
				vec2 peresech = sphIntersect(ro,rd, vec3(objects[LEN_OBJ * i+1],objects[LEN_OBJ * i +2],objects[LEN_OBJ * i +3]), objects[LEN_OBJ * i +4] );
				if( ((peresech.x>=0 && peresech.y>=0) || (peresech.x<=0 && peresech.y>=0))  && (peresech.x<min_lenght && peresech.y <min_lenght) ){
					id=i;
					if (peresech.x>=0){
						min_lenght=peresech.x;
					}
					else{
						min_lenght=peresech.y;
					}
					if (objects[LEN_OBJ * i +10]==1.0){
						min_lenght=peresech.y;
					}
				
				}
			} //CIRCLE INTERCECT
		

			if (objects[LEN_OBJ * i ]==2.0 ){
				vec3 peresech = triIntersect(ro,rd, vec3(objects[LEN_OBJ * i+1],objects[LEN_OBJ * i +2],objects[LEN_OBJ * i +3]),
													vec3(objects[LEN_OBJ * i+4],objects[LEN_OBJ * i +5],objects[LEN_OBJ * i +6]),
													vec3(objects[LEN_OBJ * i+7],objects[LEN_OBJ * i +8],objects[LEN_OBJ * i +9])  );

				if( (peresech.x>0) && (peresech.x<min_lenght) ){
					id=i;
					min_lenght=peresech.x;
				}
				
			}//TRIANLE INTERCECT
		}
		
		
	}
	
	//if (id==-1){id=0;}
	return vec2(id,min_lenght);
	
}



vec4 Raytrace(in vec3 input_ro, in vec3 input_rd){   //										*******************MAIN RAYTRACE**********************

	vec2 p;
	vec4 obj_color;
	float mat;
	vec3 normal_for_obj;
	vec3 coords;
	vec3 prev_ro;
	float coef_prelom;
	float angle;
	vec3 ro;
	vec3 rd;
	float light_str;
	float lenght;
	int id;
	bool is_light;
	vec4 res=vec4(1.0);

	for(int n_ray=0;n_ray<COUNT_RAYS;n_ray++){

			ro=input_ro; // RESET 
			rd=input_rd;
			light_str=1.0;
			lenght=9999999;
			id=-1;
			res=vec4(1.0);
			is_light=false;


			for(int i=0;i<MAX_REFLECT;i++){
				if (light_str==0.0){ break;} // if Light is so f*cking dark

				p=Ray_intersect(ro,rd,id); // GET point of cross
				id = int( p.x);

				prev_ro=ro;
				ro=ro+(rd*p.y);
		

			
				if (objects[LEN_OBJ * id]==1.0){
					obj_color=vec4(objects[LEN_OBJ * id+5],objects[LEN_OBJ * id+6],objects[LEN_OBJ * id+7],1.0);
					mat = objects[LEN_OBJ * id+8];
					normal_for_obj= ( vec3(objects[LEN_OBJ * id+1],objects[LEN_OBJ * id+2],objects[LEN_OBJ * id+3])-ro);
					coef_prelom=objects[LEN_OBJ * id+9];
				}  // OBJ_Color and MAT
				else{
					if (objects[LEN_OBJ * id]==2.0){
						obj_color=vec4(objects[LEN_OBJ * id+10],objects[LEN_OBJ * id+11],objects[LEN_OBJ * id+12],1.0);
						coef_prelom=objects[LEN_OBJ * id+14];

						mat = objects[LEN_OBJ * id+13];
						normal_for_obj= (cross(
							vec3(objects[id*LEN_OBJ+4],objects[id*LEN_OBJ+5],objects[id*LEN_OBJ+6])-vec3(objects[id*LEN_OBJ+1],objects[id*LEN_OBJ+2],objects[id*LEN_OBJ+3]),
							vec3(objects[id*LEN_OBJ+7],objects[id*LEN_OBJ+8],objects[id*LEN_OBJ+9])-vec3(objects[id*LEN_OBJ+1],objects[id*LEN_OBJ+2],objects[id*LEN_OBJ+3])
							));
					}
				}
				
				MAS_COLORS[(i*LEN_FOR_COLOR)+0]=obj_color.x;
				MAS_COLORS[(i*LEN_FOR_COLOR)+1]=obj_color.y;
				MAS_COLORS[(i*LEN_FOR_COLOR)+2]=obj_color.z;

				

				is_light=false;											// is this Light?
				for(int light_id=0; light_id<COUNT_LIGHTS;light_id++){
					if (id==ID_LIGHTS[light_id]){
						is_light=true;
						MAS_COLORS[(i*LEN_FOR_COLOR)+3]=STR_LIGHTS[light_id];
						break;
					}
				}
				
				
				MAS_COLORS[(i*LEN_FOR_COLOR)+3]=-1;
				
				


				normal_for_obj= normalize(normal_for_obj);
				

				
				random_num=vec2(time*n_ray*ro.x,time*n_ray*ro.y);//REFLECT
				if (random(random_num)>mat){
					rd =  normal_for_obj;
					rd = normalize(rd);
					random_num=vec2(time*n_ray*ro.x*3,time*n_ray*ro.y*1.1);
					rd.zx *= rotate(random(random_num)*pi);
					random_num=vec2(time*n_ray*ro.x*31,time*n_ray*ro.y*12.1);
					rd.xy *= rotate(random(random_num)*pi);
					
				} 
				else{
					rd =  refract(rd,normal_for_obj,coef_prelom);
					rd = normalize(rd);
					
				}  // elssses
			
				
			}// reflect i
			res=MIX_colors();
			MAS_RAYS_COLORS[(n_ray*LEN_FOR_COLOR)+0]=res.x;
			MAS_RAYS_COLORS[(n_ray*LEN_FOR_COLOR)+1]=res.x;
			MAS_RAYS_COLORS[(n_ray*LEN_FOR_COLOR)+2]=res.x;
			MAS_RAYS_COLORS[(n_ray*LEN_FOR_COLOR)+3]=1.0;
	
	
	}//n_ray
	
	/*return vec4(MAS_COLORS[0],
				MAS_COLORS[1],
				MAS_COLORS[2],
				MAS_COLORS[3]);
				*/
	return MIX_ray_colors();

}




void main( void ) {
	
	fill_colors();
	
	vec2 p = gl_FragCoord.xy / resolution.xy;
	vec2 angle_view;
	angle_view.x=(p.x-0.5)*2;
	angle_view.y=(p.y-0.5)*2 / (resolution.x/resolution.y);
	

	vec3 p_dir;
	p_dir.x = 1;
	p_dir.y = angle_view.x;
	p_dir.z = angle_view.y;
	
	p_dir =normalize(p_dir);
	vec4 res;
	p_dir.zx *= rotate(-player_dir_angle.y);
	p_dir.xy *= rotate(player_dir_angle.x);

	

	

	res = Raytrace(player_pos,p_dir);



	
	colorout = res;
}