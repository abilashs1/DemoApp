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
bool switch_ = false;
void MouseHandler::onEvent(Event * e)
{
	WindowsEvent* event = static_cast<WindowsEvent*>(e);
	if (event != nullptr)
	{
		switch (event->eventCode())
		{
			case EventCode::MOUSEMOVE:
			{
				switch_ = !switch_;
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

bool MouseHandler::direction(MouseCode t)
{
	if (switch_)
		return true;
	else
		return false;

	if (prvY - curY > m_delta && (MouseCode::East == t))
		return true;

	if (curY - prvY > m_delta && (MouseCode::West == t))
		return true;

	if (prvX - curX > m_delta && (MouseCode::North == t))
		return true;

	if (curX - prvX > m_delta && (MouseCode::South == t))
		return true;
	std::cout << __FILE__ << __func__<<std::endl;
	return true;
}
