#include "Shaders.h"
#include "FileSystem.h"

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	vertexShader = LoadShader(GL_VERTEX_SHADER, fileVertexShader);
	if ( vertexShader == 0 )
		return -1;

	fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);

	if ( fragmentShader == 0 )
	{
		glDeleteShader( vertexShader );
		return -2;
	}
	program = LoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	a_position = glGetAttribLocation(program, "a_position");
	a_color= glGetAttribLocation(program, "a_color");

	return 0;
}
/// \brief Load a shader, check for compile errors, print error messages to output log
/// \param type Type of shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER)
/// \param Shaderrc Shader source string
/// \return A new shader object on success, 0 on failure
//
GLuint Shaders::LoadShader ( GLenum type, const char * filename )
{
	GLuint shader;
	GLint compiled;

	// Create the shader object
	shader = glCreateShader ( type );

	if ( shader == 0 )
	return 0;

	

	char * Shaderrc = FileSystem::GetInstance()->GetContent(filename);


	glShaderSource ( shader, 1, (const char **)&Shaderrc, NULL );
	delete [] Shaderrc;

	// Compile the shader
	glCompileShader ( shader );

	// Check the compile status
	glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

	if ( !compiled ) 
	{
		GLint infoLen = 0;

		glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );

		if ( infoLen > 1 )
		{
			char* infoLog = new char  [infoLen];


			glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
			LOGI ( "Error compiling shader:\n%s\n", infoLog );            

			delete [] infoLog;
		}

		glDeleteShader ( shader );
		return 0;
	}

	return shader;
}

/// \brief Create a program object, link program.
//         Errors output to log.
/// \param vertShaderrc Vertex shader source code
/// \param fragShaderrc Fragment shader source code
/// \return A new program object linked with the vertex/fragment shader pair, 0 on failure

GLuint Shaders::LoadProgram ( GLuint vertexShader, GLuint fragmentShader )
{
	GLuint programObject;
	GLint linked;

	// Create the program object
	programObject = glCreateProgram ( );

	if ( programObject == 0 )
		return 0;

	glAttachShader ( programObject, vertexShader );
	glAttachShader ( programObject, fragmentShader );

	// Link the program
	glLinkProgram ( programObject );

	// Check the link status
	glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

	if ( !linked ) 
	{
		GLint infoLen = 0;

		glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );

		if ( infoLen > 1 )
		{
			char* infoLog = new char[sizeof(char) * infoLen];


			glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
			LOGI ( "Error linking program:\n%s\n", infoLog );            

			delete infoLog;
		}

		glDeleteProgram ( programObject );
		return 0;
	}

	return programObject;
}
Shaders::~Shaders()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}