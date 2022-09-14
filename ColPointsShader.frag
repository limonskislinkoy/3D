#version 460
const int MAX_OBJ=3;
const int LEN_OBJ=4;


uniform float objects[MAX_OBJ*LEN_OBJ];
out vec4 colorout;

float len_from (float x1,float y1,float x2,float y2){
	return sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2));
}

void main( void ) {	
	vec2 p=gl_FragCoord.xy;
	colorout = vec4(len_from(p.x,p.y,objects[0*4+0],objects[0*4+1])/1000,len_from(p.x,p.y,objects[1*4+0],objects[1*4+1])/1000,len_from(p.x,p.y,objects[2*4+0],objects[2*4+1])/1000,1.0);
	
}