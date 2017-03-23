#pragma once
#include "EventHandler.h"

enum KeyCode : unsigned
{
	BKSPC = 8,
	ENTER = 13,
	SHIFT = 16,
	CTRL = 17,
	ESCAPE = 27,
	SPACE = 32,
	PGUP = 33,
	PGDWN = 34,
	LEFT_ARROW = 37,
	UP_ARROW = 38,
	RIGHT_ARROW = 39,
	DOWN_ARROW = 40,
	ONE = 49,
	TWO = 50,
	THREE = 51,
	FOUR = 52,
	FIVE = 53,
	SIX = 54,
	SEVEN = 55,
	EIGHT = 56,
	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,
	F1 = 112,
	F2 = 113,
	F3 = 114,
	F4 = 115,
	F5 = 116,
	F6 = 117
};


class KeyboardHandler:public EventHandler
{
public:

	KeyboardHandler();
	KeyboardHandler(const KeyboardHandler&) = delete;
	KeyboardHandler& operator=(const KeyboardHandler& toCopy) = delete;
	~KeyboardHandler();
	
public:

	virtual void onEvent(Event*);
	virtual void run();

public:
	int width() { return m_screenWidth; }
	int width(int a) { m_screenWidth = a; return m_screenWidth; }
	int height() { return m_screenHeight; }
	int height(int a) { m_screenHeight = a; return m_screenHeight; }
public:

	bool getKey(KeyCode keyCode);
	bool getKeyDown(KeyCode keyCode);
	bool getKeyUp(KeyCode keyCode);

	void onKeyPress(int key);
	void onKeyRelease(int key);

private:
	unsigned int m_current = 0;
	bool m_key_state[2][256];
	int m_screenWidth, m_screenHeight;
};
