#include "Animal.h"
#include "AnimalFactory.h"
#include <vector>
#include <fstream>

int main()
{

	std::ifstream input{ "animale.txt" };

	if (!input.is_open())
	{
		abort();
	}

	int x; input >> x;
	std::list<Animal*> animale;

	while (x--)
	{
		animale.push_back(AnimalFactory::newInstance(input));
		std::cout << *animale.back() << '\n';
	}

	for (auto& e : animale)
	{
		delete e;
	}
}