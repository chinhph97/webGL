attribute vec3 a_position;
attribute vec4 a_color;

varying vec4 vColor;

uniform mat4 r_matrix; 

void main(void){
	gl_Position = r_matrix * vec4(a_position, 1.0);
	vColor = a_color;
}
