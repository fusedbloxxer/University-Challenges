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
	// problemFive(); // 5
	// 7

	Heap<int>::Type::MAX;

	Heap<int> a(Heap<int>::Type::MIN);

	a.push(2);
	a.push(4);
	a.push(5);
	a.push(-1);
	a.push(7);

	 a.pop();
	 a.pop();
	 a.pop();
	 a.pop();

	 a.push(-2);
	 a.pop();

	 a.push(3);

	 std::cout << a;
	return 0;
}