#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Problems.h"
#include "Heap.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// problemOne(); // 1
	sortingMethods(); // 2, 3, 4, 6, 8
	// problemFive();
	// problemSeven();

	return 0;
}