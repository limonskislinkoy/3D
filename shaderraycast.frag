#version 460

const int MAX_OBJ=20;
const int LEN_OBJ=15;
const int MAX_REFLECT=3;
const int COUNT_LIGHTS=1;
const int ID_LIGHTS[COUNT_LIGHTS] = {9};
const vec4 dark=vec4(0.0,0.0,0.0,0.0);
const vec4 nebo=vec4(52.0/255.0,192.0/255.0,235.0/255.0,1.0);

const float pi=3.1415;


uniform vec2 resolution;
uniform vec3 player_pos;
uniform vec2 player_dir_angle;
uniform float time;
uniform float objects[MAX_OBJ*LEN_OBJ];

out vec4 colorout;






vec4 mix_color(in vec4 col1,in vec4 col2, float mat, float light_str){
	vec4 col= (mat*col1+(1.0-mat)*col2)*light_str;
	return col;
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



float Mat_shadow( in vec3 ro,in int id){
	//return true;
	float coef=1.0;
	float maxcoef=-2.0;
	for (int light_i=0; light_i<COUNT_LIGHTS;light_i++){
		int light_id=ID_LIGHTS[light_i];
		bool intercept = false;
		for(int i=0; i < MAX_OBJ; i++)
			{
			if (i==light_id){continue;}


			if ( i==id){
				if (objects[id*LEN_OBJ]==1.0){
					vec3 normala  = normalize (ro-vec3(objects[id*LEN_OBJ+1],objects[id*LEN_OBJ+2],objects[id*LEN_OBJ+3]));
					vec3 rd =  normalize(vec3(objects[light_id*LEN_OBJ+1],objects[light_id*LEN_OBJ+2],objects[light_id*LEN_OBJ+3])-ro);

					coef = (dot(rd,normala)+1)/2.0;
					if(coef>maxcoef){
						maxcoef=coef;
					}
					continue;
				
				}


				if (objects[id*LEN_OBJ]==2.0){
					vec3 normala = cross(
					vec3(objects[id*LEN_OBJ+4],objects[id*LEN_OBJ+5],objects[id*LEN_OBJ+6])-vec3(objects[id*LEN_OBJ+1],objects[id*LEN_OBJ+2],objects[id*LEN_OBJ+3]),
					vec3(objects[id*LEN_OBJ+7],objects[id*LEN_OBJ+8],objects[id*LEN_OBJ+9])-vec3(objects[id*LEN_OBJ+1],objects[id*LEN_OBJ+2],objects[id*LEN_OBJ+3])
					);
					normala=normalize(normala);
					vec3 rd =  normalize(vec3(objects[light_id*LEN_OBJ+1],objects[light_id*LEN_OBJ+2],objects[light_id*LEN_OBJ+3])-ro);
					float sovector=dot(rd,normala);
					coef = ( (sovector)+1)/2.0;
					if(coef>maxcoef){
						maxcoef=coef;
					}
					continue;
				}
				
			}




			if (objects[i*LEN_OBJ] == 1.0)//                                                                             *CIRCLE*
				{
				 
					vec4 sph;
					sph.xyz=vec3(objects[i*LEN_OBJ+1],objects[i*LEN_OBJ+2],objects[i*LEN_OBJ+3]);
					sph.w=objects[i*LEN_OBJ+4];
					vec3 rd =  normalize(vec3(objects[light_id*LEN_OBJ+1],objects[light_id*LEN_OBJ+2],objects[light_id*LEN_OBJ+3])-ro);
					vec2 cross1=sphIntersect(ro,rd,sph.xyz,sph.w);
					if ((cross1.x>=0 && cross1.y>=0))
						{
						intercept=true;
						break;
						}
						
				}
			if (objects[i*LEN_OBJ] == 2.0)//																			*TRIANGLE*
				{
						vec3 p1,p2,p3;
						vec3 rd =  normalize(vec3(objects[light_id*LEN_OBJ+1],objects[light_id*LEN_OBJ+2],objects[light_id*LEN_OBJ+3])-ro);
						p1=vec3(objects[i*LEN_OBJ+1],objects[i*LEN_OBJ+2],objects[i*LEN_OBJ+3]);
						p2=vec3(objects[i*LEN_OBJ+4],objects[i*LEN_OBJ+5],objects[i*LEN_OBJ+6]);
						p3=vec3(objects[i*LEN_OBJ+7],objects[i*LEN_OBJ+8],objects[i*LEN_OBJ+9]);
						
						vec3 cross1=triIntersect(ro,rd,p1,p2,p3);
						if (cross1.x>0){
							intercept=true;
							break;
							
						}
						
				}

			}
		if (!intercept){
			return maxcoef;
		}
		
	}
	return 0.0;
	
}


mat2 rotate(float a) {
	float s = sin(a);
	float c = cos(a);
	return mat2(c, -s, s, c);
}


vec4 Raycast(in vec3 player_pos, in vec3 p_dir, vec4 res, float light_str){   //										*******************MAIN RAYCAST**********************
	int idmin=-1;
	int lastid=-1;
	vec3 ro=player_pos;
	vec3 rd= p_dir;
	float mat=1.0;
	float zerkalo=0.0;
	float mat_prev;

	vec4 colorp=res;
	for (int c_reflect=0; c_reflect<MAX_REFLECT; c_reflect++)
	{
		float lmin=10001;
		idmin =-1;
		
		for(int i=0; i < MAX_OBJ; i++)
		{	
				if (i!=lastid){
					if (objects[i*LEN_OBJ] == 1.0) //																			*CIRCLE*
					{
							vec4 sph;
							sph.xyz=vec3(objects[i*LEN_OBJ+1],objects[i*LEN_OBJ+2],objects[i*LEN_OBJ+3]);
							sph.w=objects[i*LEN_OBJ+4];
						
							vec2 cross1=sphIntersect(ro,rd,sph.xyz,sph.w);
							if (cross1.x>=0 && cross1.y>=0 && cross1.x<lmin && cross1.y<lmin){
								colorp=vec4(objects[i*LEN_OBJ+5],objects[i*LEN_OBJ+6],objects[i*LEN_OBJ+7],1.0);
								idmin=i;
								if (objects[i*LEN_OBJ+9]==0.0){lmin=cross1.x;}
								else{lmin=cross1.y;}
								
							
							}
						
					}

					if (objects[i*LEN_OBJ] == 2.0)//																			*TRIANGLE*
					{
							vec3 p1,p2,p3;

							p1=vec3(objects[i*LEN_OBJ+1],objects[i*LEN_OBJ+2],objects[i*LEN_OBJ+3]);
							p2=vec3(objects[i*LEN_OBJ+4],objects[i*LEN_OBJ+5],objects[i*LEN_OBJ+6]);
							p3=vec3(objects[i*LEN_OBJ+7],objects[i*LEN_OBJ+8],objects[i*LEN_OBJ+9]);
						
							vec3 cross1=triIntersect(ro,rd,p1,p2,p3);
							if (cross1.x>0 && cross1.x<lmin){
								colorp=vec4(objects[i*LEN_OBJ+10],objects[i*LEN_OBJ+11],objects[i*LEN_OBJ+12],1.0);
								idmin=i;
								lmin=cross1.x;
							
							}
						
					}
				}
				

		}
		if (idmin!=-1){	lastid=idmin;}
		

		if ((idmin==-1)){
			if (c_reflect==0){return nebo;}
			else{
				res=mix_color( res,nebo, mat_prev , light_str);
				return res;
			}
			
			/*if (End_of_ray_with_lights(ro, lastid)==true){
				return res;
			}
			else{
			return nebo;s
			}*/
		}
		else{
			

			vec3 crosspoint=ro+(lmin*rd);
			vec3 normal=vec3(0.0);
			if (objects[lastid*LEN_OBJ] == 1.0){
				 normal=crosspoint-vec3(objects[lastid*LEN_OBJ+1],objects[lastid*LEN_OBJ+2],objects[lastid*LEN_OBJ+3]); // only for circles
			}  //normals
			if (objects[lastid*LEN_OBJ] == 2.0){ // only for triangles
				 normal = cross(
				vec3(objects[lastid*LEN_OBJ+4],objects[lastid*LEN_OBJ+5],objects[lastid*LEN_OBJ+6])-vec3(objects[lastid*LEN_OBJ+1],objects[lastid*LEN_OBJ+2],objects[lastid*LEN_OBJ+3]),
				vec3(objects[lastid*LEN_OBJ+7],objects[lastid*LEN_OBJ+8],objects[lastid*LEN_OBJ+9])-vec3(objects[lastid*LEN_OBJ+1],objects[lastid*LEN_OBJ+2],objects[lastid*LEN_OBJ+3])
				);
			}
			
			normal= normalize(normal);
			vec3 ray_reflect= reflect(rd,normal);

			float k_prelom=0.0;
			if (objects[lastid*LEN_OBJ] == 1.0){
				k_prelom = objects[lastid*LEN_OBJ+9];
				if ( k_prelom!= 0.0){
				ray_reflect=normal;
				}
			}

			ro=crosspoint;
			rd=normalize(ray_reflect);
			bool is_light=false;
			for (int il=0;il<COUNT_LIGHTS;il++){
				if (lastid==ID_LIGHTS[il]){is_light=true;}
			}
			
			if (objects[lastid*LEN_OBJ] == 1.0){ mat=objects[lastid*LEN_OBJ+8]; zerkalo=objects[lastid*LEN_OBJ+9]; }
			if (objects[lastid*LEN_OBJ] == 2.0){ mat=objects[lastid*LEN_OBJ+13]; zerkalo=objects[lastid*LEN_OBJ+14]; }

			
			

			
			

			if (c_reflect!=MAX_REFLECT)
			{
				if(c_reflect>0){
					res=mix_color(colorp,res,mat,1.0);
				}

				mat_prev=mat;
				if (is_light){
					return res;
					}

				colorp=Mat_shadow(crosspoint,lastid)*colorp;
				res=mix_color(colorp, dark, mat , light_str);
				
				light_str=light_str*(1.0-mat);
				if (light_str==0.0){return res;}
				
				
				
			}
			else{
				return res;
			}
			
		}
		
		
	}

	//return res;
	/*
	if (End_of_ray_with_lights(ro, lastid)==true){
		return res;
	}
	else{
		return nebo;
	}*/
	
}



void main( void ) {
	int fov = 180;                                   //comment if you wanna change fov

	


	vec2 p = gl_FragCoord.xy / resolution.xy;
	vec2 angle_view;
	angle_view.x=(p.x-0.5)*2;
	angle_view.y=(p.y-0.5)*2 / (resolution.x/resolution.y);
	

	vec3 p_dir;
	p_dir.x = 1;
	p_dir.y = angle_view.x;
	p_dir.z = angle_view.y;
	p_dir =normalize(p_dir);

	vec4 res= nebo;
	p_dir.zx *= rotate(-player_dir_angle.y);
	p_dir.xy *= rotate(player_dir_angle.x);

	
	

	

	res = Raycast(player_pos,p_dir,vec4(1.0),1.0);
	colorout = res;
}