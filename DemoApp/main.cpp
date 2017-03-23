/*
Project : Windows Test Application
Abilash Subramani
E-Mail : abilash.subramani@gmail.com
*/





#define WIN32_LEAN_AND_MEAN

#include "Application.h"
#include "KeyBoardHandler.h"

int main(int argc, char **argv)
{
	Platform pltfrm = Platform::WINDOWS;

	Application demo(pltfrm);

	demo.initialise();
	
	demo.run();

	return 0;
}