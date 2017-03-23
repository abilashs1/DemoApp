#pragma once

// include Windows and Direct3D headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memory>
#include <vector>
#include "BaseWindow.h"

class Window final:public BaseWindow
{
public:
		static int FULL_SCREEN;
public:
	Window();
	Window(const Window&) = delete;
	Window& operator=(const Window& toCopy) = delete;
	~Window();
public:
	//Getter/Setter
		
	
	static LRESULT CALLBACK  WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	//float DeltaTime()					const	{ return m_game->DeltaTime(); }
	
public:
	int width(int w) { int temp = m_width;	m_width = w;	return temp; }
	int width()							const { return m_width; }
	int height(int h) { int temp = m_height; m_height = h; return temp; }
	int height()						const { return m_height; }
	HWND getHandle()					const { return m_hWnd; }
	
	void resize() {} //m_renderer->Resize(m_width, m_height); }

public:
	virtual bool initialise(int width, int height);
	virtual bool run();
private:
	bool createApplicationWindow(int width, int height);
private:

	HWND							m_hWnd;
	int								m_width, m_height;
	LPCWSTR							m_app_name;

};
