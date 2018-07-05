#include "Input.h"
#include <cstring>
#include "Engine.h"
Input::Input(void)
{
	Reset();
}


Input::~Input(void)
{
}

bool Input::KeyPressed(int keyCode)
{
	if ( keyCode >=0 && keyCode < 256)
	{
		return keyState[keyCode];
	}
	return false;
}

bool Input::KeyPressed()
{	
	return keyPressed;
}



void Input::OnKey(unsigned char keyCode, bool keyPressed)
{	
	this->keyPressed = keyPressed;
	keyState[keyCode] = keyPressed;
}

void Input::OnPointer(PointerEvent e, int x, int y)
{	
	PointerX = x;
	PointerY = y;			
	memset(pointerState, 0, sizeof(pointerState));
	pointerState[e] = true;

}

void Input::Reset()
{
	memset(keyState, 0, sizeof(keyState));
	memset(pointerState, 0, sizeof(pointerState));
	keyPressed = false;	
}

bool Input::HasPointer(PointerEvent e)
{
	bool p = pointerState[e];	
	pointerState[e] = false;
	return p;
}
