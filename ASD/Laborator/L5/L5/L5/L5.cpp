#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Problems.h"
#include "Heap.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// problemOne(); // AVL
	// sortingMethods(); // 2, 3, 6, 8
	// problemThree();
	
	Heap a;
	
	a.insert(2);
	a.insert(4);
	a.insert(5);
	a.insert(-1);
	a.insert(7);
	a.insert(-2);
	a.insert(3);

	int f = -10;
	a.insert(f);
	std::cout << a;

	_CrtDumpMemoryLeaks();
	return 0;
}