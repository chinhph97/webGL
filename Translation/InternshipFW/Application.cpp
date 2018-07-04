#include "Application.h"
#include "FileSystem.h"
#include "Shaders.h"
#include "Vertex.h"
#include "Input.h"

Shaders myShaders;

Vertex vertexData[3];
Vector4 Tran = Vector4(0,0.5,0.5,0.5);//Vector translation
GLuint b;							//buffer

// create the application here.
Application::Application()
{	
}

// Initialize current game.
int Application::Init(const char *resPath)
{		
	FileSystem::GetInstance()->Init(resPath);			
	//creation of shaders and program 
	myShaders.Init("Shaders/Basicvs.txt", "Shaders/Basicfs.txt");	
	
	vertexData[0].pos = Vector3( 0, 0.5, 0 );
	vertexData[1].pos = Vector3( -0.5, -0.5, 0 );
	vertexData[2].pos = Vector3( 0.5, -0.5, 0 );

	vertexData[0].color = Vector4(1, 0, 0, 1);
	vertexData[1].color = Vector4(0, 1, 0, 1);
	vertexData[2].color = Vector4(0, 0, 1, 1);

	glGenBuffers(1, &b);
	glBindBuffer(GL_ARRAY_BUFFER, b);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* 3, vertexData, GL_STATIC_DRAW);

	return true;
}

// Update current state
void Application::Update(float deltatime)
{
	Input * input = Input::GetInstance();	
	
	if ( input->HasPointer(POINTER_DRAGGED) )
	{
		LOGI("\nPOINTER_DRAGGED");
	}
	if ( input->HasPointer(POINTER_DOWN) )
	{
		LOGI("\nPOINTER_DOWN");
	}
	if ( input->HasPointer(POINTER_UP) )
	{
		LOGI("\nPOINTER_UP");
	}
	
	if ( input->KeyPressed() )
	{
		LOGI("\nKey Pressed");
	}
}

// Render application

void Application::Render()
{	
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(myShaders.program);	


	if(myShaders.a_position != -1)
	{
		glEnableVertexAttribArray(myShaders.a_position);
		glVertexAttribPointer(myShaders.a_position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), vertexData);
	}

	if (myShaders.a_translation != -1)
	{
		glUniform4f(myShaders.a_translation, Tran.x, Tran.y, Tran.z, Tran.w);
	}
	if (myShaders.a_color != -1)
	{
		glEnableVertexAttribArray(myShaders.a_color);
		char* ch = (char*)vertexData;
		glVertexAttribPointer(myShaders.a_color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ch+12);//fl+8
	}


	glDrawArrays(GL_TRIANGLES, 0, 3);

}

// destroy the application here.
void Application::Destroy()
{	
	Application::FreeInstance();
};

Application::~Application()
{	
	//glDeleteBuffers(1, &b);
	FileSystem::FreeInstance();
	Input::FreeInstance();		
	
}

