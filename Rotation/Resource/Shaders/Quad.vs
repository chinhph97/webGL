attribute vec3 a_position;
attribute vec4 color;
varying vec4 vColor;

void main()
{
	vec4 positionL = vec4(a_position, 1.0);
	gl_Position = positionL;
	vColor = color;
}
   
   