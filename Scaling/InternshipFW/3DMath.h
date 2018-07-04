#pragma once

#include "Engine.h"

//Vector2

class Vector2
{
public:
	//Constructors
	Vector2() : x(0.0f), y(0.0f){}
	Vector2(GLfloat _x, GLfloat _y) : x(_x), y(_y) {}
	Vector2(GLfloat * pArg) : x(pArg[0]), y(pArg[1]) {}

	//Vector's operations
	GLfloat Length() const;
	Vector2 & Normalize();
	Vector2 operator + (const Vector2 & vector) const;
	Vector2 & operator += (const Vector2 & vector);
	Vector2 operator - () const;
	Vector2 operator - (const Vector2 & vector) const;
	Vector2 & operator -= (const Vector2 & vector);
	Vector2 operator * (GLfloat k) const;
	Vector2 & operator *= (GLfloat k);
	Vector2 operator / (GLfloat k) const;
	Vector2 & operator /= (GLfloat k);	
	Vector2 Modulate(const Vector2 & vector) const;
	GLfloat Dot(const Vector2 & vector) const;

	//access to elements
	GLfloat operator [] (unsigned int idx) const;

	//data members
	GLfloat x;
	GLfloat y;
};

//Vector3
class Vector4;
class Vector3
{
public:
	//Constructors
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) {}
	Vector3(GLfloat * pArg) : x(pArg[0]), y(pArg[1]), z(pArg[2]) {}	
	Vector3( const Vector4 & vec) ;
	//Vector's operations
	GLfloat Length() const;
	Vector3 & Normalize();
	Vector3 operator + (const Vector3 & vector) const;
	Vector3 & operator += (const Vector3 & vector) ;
	Vector3 operator - () const;
	Vector3 operator - (const Vector3 & vector) const;
	Vector3 & operator -= (const Vector3 & vector);
	Vector3 operator * (GLfloat k) const;
	Vector3 & operator *= (GLfloat k);
	Vector3 operator / (GLfloat k) const;
	Vector3 & operator /= (GLfloat k);
	Vector3 Modulate(const Vector3 & vector) const;
	GLfloat Dot(const Vector3 & vector) const;
	Vector3 Cross(const Vector3 & vector) const;

	//access to elements
	GLfloat operator [] (unsigned int idx) const;

	// data members
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//Vector4

class Vector4
{
public:
	//Constructors
	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	Vector4(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z), w(1.0f) {}
	Vector4(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) : x(_x), y(_y), z(_z), w(_w) {}
	Vector4(GLfloat * pArg) : x(pArg[0]), y(pArg[1]), z(pArg[2]), w(pArg[3]) {}
	Vector4(const Vector3 & vector) : x(vector.x), y(vector.y), z(vector.z), w(1.0f){}
	Vector4(const Vector3 & vector, GLfloat _w) : x(vector.x), y(vector.y), z(vector.z), w(_w) {}	

	//Vector's operations
	GLfloat Length() const;
	Vector4 & Normalize();
	Vector4 operator + (const Vector4 & vector) const;
	Vector4 & operator += (const Vector4 & vector);
	Vector4 operator - () const;
	Vector4 operator - (const Vector4 & vector) const;
	Vector4 & operator -= (const Vector4 & vector);
	Vector4 operator * (GLfloat k) const;
	Vector4 & operator *= (GLfloat k);
	Vector4 operator / (GLfloat k) const;
	Vector4 & operator /= (GLfloat k);	
	Vector4 Modulate(const Vector4 & vector) const;
	GLfloat Dot(const Vector4 & vector) const;

	//access to elements
	GLfloat operator [] (unsigned int idx) const;

	//data members
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
};

//Matrix 4 X 4


class Matrix
{
public:
	//constructors
	Matrix() {}
	Matrix(GLfloat val);	

	// Matrix operations
	Matrix & SetZero();
	Matrix & SetIdentity();

	Matrix & SetRotationX(GLfloat angle);
	Matrix & SetRotationY(GLfloat angle);
	Matrix & SetRotationZ(GLfloat angle);
	
	Matrix & SetRotaionZXY(GLfloat angleX, GLfloat angleY, GLfloat angleZ );
	Matrix & SetRotaionZXY(const Vector3 & rotation);
	Matrix & SetRotaionZXY( GLfloat * pRotation);
	
	Matrix & SetRotaionYXZ(GLfloat angleX, GLfloat angleY, GLfloat angleZ );
	Matrix & SetRotaionYXZ(const Vector3 & rotation);
	Matrix & SetRotaionYXZ( GLfloat * pRotation);

	Matrix & SetRotationAngleAxis( float angle, float x, float y, float z );

	Matrix & SetScale(GLfloat scale);
	Matrix & SetScale(GLfloat scaleX, GLfloat scaleY, GLfloat scaleZ);
	Matrix & SetScale(GLfloat * pScale);
	Matrix & SetScale(const Vector3 &scaleVec);


	Matrix & SetTranslation(GLfloat x, GLfloat y, GLfloat z);
	Matrix & SetTranslation(GLfloat *pTrans);
	Matrix & SetTranslation(const Vector3 &vec);


	Matrix & SetPerspective(GLfloat fovY, GLfloat aspect, GLfloat nearPlane, GLfloat farPlane);
	Matrix & SetOrtho(float left, float right, float bottom, float top, float near, float far);

	Matrix Transpose() const;

	Matrix operator + (const Matrix & mat) const;
	Matrix & operator += (const Matrix & mat);
	Matrix operator - (const Matrix & mat) const;
	Matrix &operator -= (const Matrix & mat);

	Matrix operator * (const Matrix & mat) const;
	Matrix operator * (GLfloat k) const;
	Matrix & operator *= (GLfloat k);

	Vector4 operator * (const Vector4 & vec) const;	

	//data members
	GLfloat m[4][4];
};
