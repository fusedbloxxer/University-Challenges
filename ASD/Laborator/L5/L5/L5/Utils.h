#pragma once

namespace Utils
{
	template<typename T>
	T min(T a, T b)
	{
		if (a < b) return a;
		return b;
	}

	template<typename T>
	T max(T a, T b)
	{
		if (a > b) return a;
		return b;
	}

	template<typename T>
	T abs(T a)
	{
		return ((a >= 0) ? a : a * -1);
	}

	template<typename T>
	int sgn(T a)
	{
		return ((a >= 0) ? 1 : -1);
	}

	template<typename T>
	bool dis(T a, T b)
	{
		return sgn(a) != sgn(b);
	}
}