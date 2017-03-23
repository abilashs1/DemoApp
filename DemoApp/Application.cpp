#include "Application.h"

#include "System.h"
#include "KeyBoardHandler.h"
#include "KeyboardController.h"
#include "MouseHandler.h"
#include "MouseController.h"
Application::Application(Platform type):m_platform(type)
{
	
}


Application::~Application()
{
}

void Application::initialise()
{
	m_system = std::make_unique<System>(m_platform);

	{
		auto mouse = m_system->addEventHandler<MouseHandler>(m_platform);
		auto ctr = m_system->addController<MouseController>(mouse);
		auto obj = m_system->addObject<Object>(1);
		obj->setController(ctr);
		mouse->registerEvent(EventCode::MOUSEMOVE);
	}
	{
		auto kbd = m_system->addEventHandler<KeyboardHandler>(m_platform);
		auto ctr = m_system->addController<KeyboardController>(kbd);
		auto obj = m_system->addObject<Object>(2);
		obj->setController(ctr);
		kbd->registerEvent(EventCode::KEYDOWN);
		kbd->registerEvent(EventCode::KEYUP);
	}
}

void Application::run()
{
	m_system->run();
	
}

void Application::initialiseHandler()
{
	
}
