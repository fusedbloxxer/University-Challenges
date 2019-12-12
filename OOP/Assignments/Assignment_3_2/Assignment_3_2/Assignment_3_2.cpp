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

	int x; input >> x; char ch; input.get(ch);
	std::list<Animal*> animale;

	while (x)
	{
		animale.push_back(AnimalFactory::newInstance(input));
		std::cout << *animale.back() << '\n';
		x--;
	}

	for (auto& e : animale)
	{
		delete e;
	}
}