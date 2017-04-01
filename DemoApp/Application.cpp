#include "Application.h"

#include "System.h"
#include "KeyBoardHandler.h"
#include "MouseHandler.h"
#include "CarController.h"
#include "FlightController.h"
Application::Application(Platform type):m_platform(type)
{
	
}


Application::~Application()
{
}

void Application::initialise()
{
	m_system = std::make_unique<System>(m_platform);
	auto mouse = m_system->addEventHandler<MouseHandler>(m_platform);
	mouse->registerEvent(EventCode::MOUSEMOVE);

	auto kbd = m_system->addEventHandler<KeyboardHandler>(m_platform);
	kbd->registerEvent(EventCode::KEYDOWN);
	kbd->registerEvent(EventCode::KEYUP);

	auto fctrK = m_system->addController<FlightController>(kbd);
	auto fctrM = m_system->addController<FlightController>(mouse);
	auto ctrM = m_system->addController<CarController>(mouse);
	auto ctrK = m_system->addController<CarController>(kbd);
	
	{
		
		
		auto obj = m_system->addObject<Object>(1);
		obj->setController(fctrM);
		
	}
	{
		
		
		auto obj = m_system->addObject<Object>(2);
		obj->setController(fctrK);
	
	}
	{
		
		
		auto obj = m_system->addObject<Object>(3);
		obj->setController(ctrK);

	}
	{
		
		auto obj = m_system->addObject<Object>(4);
		obj->setController(ctrM);
		
	}

}

void Application::run()
{
	m_system->run();
	
}

void Application::initialiseHandler()
{
	
}
