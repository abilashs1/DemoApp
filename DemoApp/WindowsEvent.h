#pragma once
#include "Event.h"
#include <windows.h>

class WindowsEvent final:
	public Event
{
public:
	WindowsEvent();
	virtual ~WindowsEvent();
	UINT message(UINT msg);
	UINT message();
	WPARAM w_param(WPARAM wParam);
	WPARAM w_param();
	LPARAM l_param(LPARAM wParam);
	LPARAM l_param();
private:
	UINT m_message;
	WPARAM m_wParam;
	LPARAM m_lParam;
};