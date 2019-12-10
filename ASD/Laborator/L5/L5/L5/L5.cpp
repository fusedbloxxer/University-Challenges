#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Problems.h"
#include "Heap.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// problemOne(); // 1
	//sortingMethods(); // 2, 3, 4, 6, 8
	// problemFive();
	// problemSeven();

	Heap<int> h(Heap<int>::MAX);
	h.push(2);
	h.push(-3);
	h.push(7);
	h.push(1);
	h.push(10);
	h.push(-3);

	std::cout << h;

	return 0;
}