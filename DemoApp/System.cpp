#include "System.h"


System::System(Platform type)
{
	if (type == Platform::WINDOWS)
	{
		auto win = new Window();
		m_window = win;
		m_window = new Window();
		m_window->initialise(800, 600);
	}
}


System::~System()
{

}


bool System::run()
{
	bool quit = false;
	while (!quit)
	{
		if (!m_window->run())
			quit = true;
		for (auto& object : m_objects)
			object->run();
	}
	return true;
}

