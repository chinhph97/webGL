#include "Application.h"
#include "FileSystem.h"
#include "Shaders.h"
#include "Vertex.h"
#include "Input.h"

Shaders myShaders;

Vertex vertexData[24];
Matrix Rotation;
int Indi[] = {
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7,
	8, 9, 10, 8, 10, 11,
	12, 13, 14, 12, 14, 15,
	16, 17, 18, 16, 18, 19,
	20, 21, 22, 20, 22, 23,
};
GLfloat Angle[] = { 0.01, 0.01, 0.01 };
GLuint B;

// create the application here.
Application::Application()
{	
}

// Initialize current game.
int Application::Init(const char *resPath)
{		
	FileSystem::GetInstance()->Init(resPath);			
	//creation of shaders and program 
	myShaders.Init("Shaders/Basic.vs", "Shaders/Basic.fs");	
	
	vertexData[0].pos = Vector3(-0.5, 0.5, 0.5);
	vertexData[1].pos = Vector3(-0.5, 0.5, -0.5);
	vertexData[2].pos = Vector3(0.5, 0.5, -0.5);
	vertexData[3].pos = Vector3(0.5, 0.5, 0.5);

	vertexData[4].pos = Vector3(-0.5, -0.5, 0.5);
	vertexData[5].pos = Vector3(-0.5, -0.5, -0.5);
	vertexData[6].pos = Vector3(0.5, -0.5, -0.5);
	vertexData[7].pos = Vector3(0.5, -0.5, 0.5);

	vertexData[8].pos = Vector3(-0.5, 0.5, 0.5);
	vertexData[9].pos = Vector3(-0.5, 0.5, -0.5);
	vertexData[10].pos = Vector3(-0.5, -0.5, -0.5);
	vertexData[11].pos = Vector3(-0.5, -0.5, 0.5);

	vertexData[12].pos = Vector3(-0.5, 0.5, 0.5);
	vertexData[13].pos = Vector3(0.5, 0.5, 0.5);
	vertexData[14].pos = Vector3(0.5, -0.5, 0.5);
	vertexData[15].pos = Vector3(-0.5, -0.5, 0.5);

	vertexData[16].pos = Vector3(0.5, 0.5, 0.5);
	vertexData[17].pos = Vector3(0.5, 0.5, -0.5);
	vertexData[18].pos = Vector3(0.5, -0.5, -0.5);
	vertexData[19].pos = Vector3(0.5, -0.5, 0.5);

	vertexData[20].pos = Vector3(-0.5, 0.5, -0.5);
	vertexData[21].pos = Vector3(0.5, 0.5, -0.5);
	vertexData[22].pos = Vector3(0.5, -0.5, -0.5);
	vertexData[23].pos = Vector3(-0.5, -0.5, -0.5);

	vertexData[0].color = Vector4(1, 0, 0, 1);
	vertexData[1].color = Vector4(1, 0, 0, 1);
	vertexData[2].color = Vector4(1, 0, 0, 1);
	vertexData[3].color = Vector4(1, 0, 0, 1);

	vertexData[4].color = Vector4(0, 1, 0, 1);
	vertexData[5].color = Vector4(0, 1, 0, 1);
	vertexData[6].color = Vector4(0, 1, 0, 1);
	vertexData[7].color = Vector4(0, 1, 0, 1);

	vertexData[8].color = Vector4(0, 0, 1, 1);
	vertexData[9].color = Vector4(0, 0, 1, 1);
	vertexData[10].color = Vector4(0, 0, 1, 1);
	vertexData[11].color = Vector4(0, 0, 1, 1);

	vertexData[12].color = Vector4(1, 0, 1, 1);
	vertexData[13].color = Vector4(1, 0, 1, 1);
	vertexData[14].color = Vector4(1, 0, 1, 1);
	vertexData[15].color = Vector4(1, 0, 1, 1);

	vertexData[16].color = Vector4(1, 1, 0, 1);
	vertexData[17].color = Vector4(1, 1, 0, 1);
	vertexData[18].color = Vector4(1, 1, 0, 1);
	vertexData[19].color = Vector4(1, 1, 0, 1);

	vertexData[20].color = Vector4(1, 1, 1, 1);
	vertexData[21].color = Vector4(1, 1, 1, 1);
	vertexData[22].color = Vector4(1, 1, 1, 1);
	vertexData[23].color = Vector4(1, 1, 1, 1);

	glGenBuffers(1, &B);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, B);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indi), Indi, GL_STATIC_DRAW);

	//Rotation.SetRotationY(*Angle);
	Rotation.SetRotaionZXY(Angle);

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
	glEnable(GL_DEPTH_TEST);

	glUseProgram(myShaders.program);	


	if(myShaders.a_position != -1)
	{
		glEnableVertexAttribArray(myShaders.a_position);
		glVertexAttribPointer(myShaders.a_position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), vertexData);
	}
	if (myShaders.a_color != -1)
	{
		glEnableVertexAttribArray(myShaders.a_color);
		GLfloat * ch = (GLfloat*)vertexData;
		glVertexAttribPointer(myShaders.a_color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ch + 3);
	}
	glUniformMatrix4fv(myShaders.r_matrix, 1, GL_FALSE, (const GLfloat*)Rotation.m);

	//change current coordinates 
	for (register int i = 0; i < sizeof(vertexData) / sizeof(Vertex); i++) {
		multiple(Rotation, vertexData[i].pos);
	}
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, sizeof(Indi) / sizeof(int), GL_UNSIGNED_INT, nullptr);

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

