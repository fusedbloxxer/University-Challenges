#pragma once
#include <iostream>

class Logger
{
	inline static int priority = 15;

public:
	template<typename Object>
	static void wtf(Object object, bool show = true);

	template<typename Object>
	static void e(Object object, bool show = true);

	template<typename Object>
	static void d(Object object, bool show = true);

	template<typename Object>
	static void v(Object object, bool show = true);

	static void setMode(int priority);

	static int getMode();
private:
	static void setColor(int colorCode);
};

/*
The different color codes are

0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/

// BIT OPERATIONS: verbose, debug, error, what a terrible failure
//                    3       2      1          0 

template<typename Object>
void Logger::wtf(Object object, bool show)
{
	if (show && (priority & 1) != 0)
	{
		Logger::setColor(4);
		std::cout << object;
		Logger::setColor(15);
	}
}

template<typename Object>
void Logger::e(Object object, bool show)
{
	if (show && (priority & (1 << 1)) != 0)
	{
		Logger::setColor(2);
		std::cout << object;
		Logger::setColor(15);
	}
}

template<typename Object>
void Logger::d(Object object, bool show)
{
	if (show && (priority & (1 << 2)) != 0)
	{
		Logger::setColor(1);
		std::cout << object;
		Logger::setColor(15);
	}
}

template<typename Object>
void Logger::v(Object object, bool show)
{
	if (show && (priority & (1 << 3)) != 0)
	{
		Logger::setColor(14);
		std::cout << object;
		Logger::setColor(15);
	}
}