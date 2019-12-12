#include <iostream>
#include "Stiva.h"
#include "Queue.h"

void pureImag(Vector<>& container) {
	if (PureImag_I * imag = dynamic_cast<PureImag_I*>(&container)) {
		std::cout << "Is pure: " << std::boolalpha << imag->isPure() << std::endl;
	}
}

void tryContainer(Vector<>&& container)
{
	container.push({ 0, -4 });
	std::cout << container << std::endl;
	pureImag(container);

	container.push({ 0, 0 });
	std::cout << container << std::endl;
	pureImag(container);

	container.push({ 1, 5 });
	std::cout << container << std::endl;
	pureImag(container);

	std::cout << container << std::endl;

	std::cout << "Popped element: " << container.pop() << std::endl;
	std::cout << "Popped element: " << container.pop() << std::endl;
	pureImag(container);

	std::cout << container << std::endl;

	container.push({ 1, 0 });
	container.push({ 2, 5 });

	std::cout << container << std::endl;

	// Throw PopException
	std::cout << "Popped element: " << container.pop() << std::endl;
	std::cout << "Popped element: " << container.pop() << std::endl;
	std::cout << "Popped element: " << container.pop() << std::endl;
	std::cout << "Popped element: " << container.pop() << std::endl;
}

void start(Vector<>&& container)
{
	try
	{
		tryContainer(std::move(container));
		std::cout << std::endl;
		std::cout << std::endl;
	}
	catch (PopException& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	catch (...)
	{
		std::cout << "Some other error was thrown.";
	}
}

int main()
{
	try 
	{
		constexpr int count = 3;
		auto complex = new Complex<>[count];
		std::cout << Vector<>{count, complex} << std::endl << std::endl;

		start(Vector<>{});

		start(Stiva<>{});

		start(Queue<>{});

		auto q = Queue<>{-3, nullptr};
	}
	catch (NegativeSizeException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}