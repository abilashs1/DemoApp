#include "Window.h"
#include <stdlib.h>
#include <time.h>
#define DEBUG 1
#include "Windowsx.h"
#include "KeyboardHandler.h"
#include <iostream>

#include "WindowsEvent.h"


int Window::FULL_SCREEN = 0;

Window::Window()
	:BaseWindow(Platform::WINDOWS), m_hWnd(nullptr), m_width(800),
	m_height(600),m_app_name(nullptr)

{
	// Reset RNG
	srand(time(NULL));
}

Window::~Window()
{

	
}

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Window* win = static_cast<Window*>(BaseWindow::getInstance());

	WindowsEvent data;
	data.message(message);
	data.w_param(wParam);
	data.l_param(lParam);

	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_KEYDOWN:
	{
		
		data.eventCode(EventCode::KEYDOWN);
		
		break;
	}
	case WM_MOUSEMOVE:
	{
		data.eventCode(EventCode::MOUSEMOVE);
		//			EventHandler->OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;
	}
	case WM_SIZE:
	{
		//TheWindow->Resize();
		break;
	}
	case WM_KEYUP:
	{
		data.eventCode(EventCode::KEYUP);
		//EventHandler->OnKeyRelease(wParam);
		break;
	}
	/*default:
	printstuff(message);*/
	}
	win->handleEvent(&data);
	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool  Window::createApplicationWindow(int width, int height)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY = 0;

	m_width = width;
	m_height = height;

	//ApplicationHandle = this;		
	HINSTANCE m_hinstance = GetModuleHandle(NULL);


	m_app_name = L"Application";

	// Setup the windows class with default settings.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = Window::WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_app_name;
	wc.cbSize = sizeof(WNDCLASSEX);


	RegisterClassEx(&wc);

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);


	if (FULL_SCREEN)
	{
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = static_cast<unsigned long>(screenWidth);
		dmScreenSettings.dmPelsHeight = static_cast<unsigned long>(screenHeight);
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		m_width = screenWidth;
		m_height = screenHeight;

		posX = posY = 0;
	}
	else
	{

		screenWidth = m_width;
		screenHeight = m_height;


		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}
	RECT wr = { 0, 0, m_width, m_height };    // set the size, but not the position
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	int style = WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	// Create the window with the screen settings and get the handle to it.
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_app_name, m_app_name, style,
		posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);

	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);


	//ShowCursor(false);
	return true;
}

bool Window::initialise(int width, int height)
{
	if (!createApplicationWindow(width, height))
		return false;

	return true;
}

bool Window::run()
{
	BaseWindow::run();
	MSG msg;

	//m_input->Run();

	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (msg.message == WM_QUIT)
	{
		return false;
	}
	return true;
}
