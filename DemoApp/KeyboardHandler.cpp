#include "KeyboardHandler.h"
#include <cstring>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define DEBUG 1
#include "WindowsEvent.h"

KeyboardHandler::KeyboardHandler()
	:m_current(0), m_key_state()
{
}

KeyboardHandler::~KeyboardHandler()
{
}

bool KeyboardHandler::getKey(KeyCode keyCode)
{
	return m_key_state[0][static_cast<unsigned int>(keyCode)];
	std::cout << __FILE__ << __func__ << std::endl;
}

bool KeyboardHandler::getKeyDown(KeyCode keyCode)
{
	return m_key_state[0][static_cast<unsigned int>(keyCode)] && m_key_state[1][static_cast<unsigned int>(keyCode)];
}

bool KeyboardHandler::getKeyUp(KeyCode keyCode)
{
	return !m_key_state[0][static_cast<unsigned int>(keyCode)] && m_key_state[1][static_cast<unsigned int>(keyCode)];
}

void KeyboardHandler::run()
{
	m_current = !m_current;
	memset(&m_key_state[1], 0x00, sizeof(m_key_state[1]));
}

void KeyboardHandler::onKeyPress(int key)
{
	m_key_state[0][key] = true;
	m_key_state[1][key] = true;
}

void KeyboardHandler::onKeyRelease(int key)
{
	m_key_state[0][key] = false;
	m_key_state[1][key] = true;
}



void KeyboardHandler::onEvent(Event* e)
{
	WindowsEvent* event = static_cast<WindowsEvent*>(e);
	if (event != nullptr)
	{
		switch (event->eventCode())
		{
			case EventCode::KEYDOWN:
			{			
				onKeyPress(event->w_param());
				break;
			}		
			case EventCode::KEYUP:
			{
				onKeyRelease(event->w_param());
				break;
			}
		}
	}
}