#include "MouseHandler.h"
#include "WindowsEvent.h"


MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}
#include <iostream>
#include "Windowsx.h"

void MouseHandler::onEvent(Event * e)
{
	WindowsEvent* event = static_cast<WindowsEvent*>(e);
	if (event != nullptr)
	{
		switch (event->eventCode())
		{
			case EventCode::MOUSEMOVE:
			{
				prvX = curX;
				prvY = curY;
				auto l_param = event->l_param();
				//std::cout << GET_X_LPARAM(l_param) << " " << GET_Y_LPARAM(l_param) <<std::endl;
				curX = GET_X_LPARAM(l_param);
				curY = GET_Y_LPARAM(l_param);
				break;
			}
		}
	}
}

void MouseHandler::run()
{
}
