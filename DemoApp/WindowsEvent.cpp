#include "WindowsEvent.h"



WindowsEvent::WindowsEvent()
{
}


WindowsEvent::~WindowsEvent()
{
}

UINT WindowsEvent::message(UINT msg)
{
	m_message = msg;
	return msg;
}
UINT WindowsEvent::message()
{
	return m_message;
}
WPARAM WindowsEvent::w_param(WPARAM wParam)
{
	m_wParam = wParam;
	return wParam;
}
WPARAM WindowsEvent::w_param()
{
	return m_wParam;
}
LPARAM WindowsEvent::l_param(LPARAM wParam)
{
	m_lParam = wParam;
	return wParam;
}
LPARAM WindowsEvent::l_param()
{
	return m_lParam;
}