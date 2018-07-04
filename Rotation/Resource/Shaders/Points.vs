attribute vec3 coordinates;

void main(){
	gl_position = vec4(coordinates, 1.0);
	int gl_PointSize = 10;
}