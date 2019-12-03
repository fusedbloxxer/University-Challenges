#include "Logger.h"
#include <iostream>
#include <windows.h>

void Logger::setMode(int priority)
{
	if (priority < 0 || priority > 15)
	{
		throw std::runtime_error{ "Wrong priority mode." };
	}

	Logger::priority = priority;
}

int Logger::getMode()
{
	return Logger::priority;
}

void Logger::setColor(int colorCode)
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}