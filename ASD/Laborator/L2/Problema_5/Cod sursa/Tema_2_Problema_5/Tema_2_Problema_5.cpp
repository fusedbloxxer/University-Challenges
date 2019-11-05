#include <iostream>
#include "BigNumber.h"

/*

(4 p) 5. Reprezentarea numerelor mari (numere întregi cu număr mare de cifre) cu ajutorul
unei liste liniare simplu înlănţuite se face folosind următoarea schemă:

Numărul întreg 82564 este reprezentat ca lista punând fiecare cifră în câte un nod.
Scrieţi un program în care se citesc două numere “mari” şi se construieşte o listă
în care se va salva suma lor.
*/

int main()
{
	// Exemplu:
	BigNumber a, b;

	for (;;)
	{
		std::cout << "Introduceti doua numere: \n"
			"Primul element: ";
		
		std::cin >> a;

		std::cout << "Al doilea element: ";

		std::cin >> b;

		std::cout << "Suma lor este: " << a + b << "\n\n";
	}
}