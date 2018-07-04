#include "Application.h"
#include "FileSystem.h"
#include "Shaders.h"
#include "Vertex.h"
#include "Input.h"

Shaders shader;
Vertex vertexData[3];
double angle =1.5;	//gocquay 1 chieu
Matrix Rotation;
GLuint VBO;


// create the application here
Application::Application()
{
}

// Initialize current game.
int Application::Init(const char *resPath)
{
	FileSystem::GetInstance()->Init(resPath);
	//creation of shaders and program 
	shader.Init("Shaders/Rotatingvs.txt", "Shaders/Rotatingfs.txt");

	vertexData[0].pos = Vector3(-0.5, -0.5, -0.5);
	vertexData[1].pos = Vector3(0.5, -0.5, -0.5);
	vertexData[2].pos = Vector3(0.5, 0.5, -0.5);

	vertexData[0].color = Vector4(1, 0, 0, 1);
	vertexData[1].color = Vector4(0, 1, 0, 1);
	vertexData[2].color = Vector4(0, 0, 1, 1);

	Rotation.SetRotationZ(angle);
	return true;
}

// Update current state
void Application::Update(float deltatime)
{
	Input * input = Input::GetInstance();

	if (input->HasPointer(POINTER_DRAGGED))
	{
		LOGI("\nPOINTER_DRAGGED");
	}
	if (input->HasPointer(POINTER_DOWN))
	{
		LOGI("\nPOINTER_DOWN");
	}
	if (input->HasPointer(POINTER_UP))
	{
		LOGI("\nPOINTER_UP");
	}

	if (input->KeyPressed())
	{
		LOGI("\nKey Pressed");
	}
}
void multiple(Matrix m, Vector3 &v) 
{
	Vector4 x = Vector4(v);
	x = m * x;
	v = Vector3(x);
}

// Render application
void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader.program);

	if (shader.a_position != -1)
	{
		glEnableVertexAttribArray(shader.a_position);
		glVertexAttribPointer(shader.a_position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), vertexData);
	}

	if (shader.color != -1)
	{
		glEnableVertexAttribArray(shader.color);
		GLfloat * pointer = (GLfloat *)vertexData;
		glVertexAttribPointer(shader.color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), pointer + 3);
	}

	glUniformMatrix4fv(shader.Rmatrix, 1, GL_FALSE, (const GLfloat*)Rotation.m);

	//change current coordinates 
	for (register int i = 0; i < sizeof(vertexData) / sizeof(Vertex); i++) {
		multiple(Rotation, vertexData[i].pos);
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
	FileSystem::FreeInstance();
	Input::FreeInstance();
}

