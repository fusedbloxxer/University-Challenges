#include <iostream>
#include <random>
#include <ctime>

// Clasa / Structura care contine un element
class Container {
	// Numar
	int value;
public:
	Container(int def = 0) : value{ def } {}

	void setValue(int value) {
		this->value = value;
	}

	int getValue() const {
		return this->value;
	}
};

// Afisarea unui vector
void print(const int* const arr, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

// Se compara doua cate doua elemente si se aduce elementul initial pe pozitia finala sortata
// si returneaza pozitia acestuia
int pivot(const Container* const container, int* const indexes, int start, int end) {
	// Ordine de parcurgere initial de la stanga la dreapta
	int i = 1, j = 0;

	// Cat timp avem doua elemente pe care le putem compara
	while (start < end)
	{
		// Daca nu sunt ordonate crescator atunci interschimbam indicii
		// si schimbam ordinea de parcurgere, dreapta - stanga sau stanga - dreapta
		if (container[indexes[start]].getValue() > container[indexes[end]].getValue())
		{
			int temp = indexes[start];
			indexes[start] = indexes[end];
			indexes[end] = temp;

			int aux = -i;
			i = -j;
			j = aux;
		}

		// Avansam folosind ordinea mentionata
		start += i;
		end += j;
	}

	// Nu mai avem doua elemente pe care le putem compara,
	// deci elementul (indicele) a ajuns pe pozitia corecta
	// si returnam pozitia acestuia
	return start;
}

// Functia de quicksort care foloseste divide et impera pentru sortarea elementelor folosind
// un vector auxiliar O(n) care contine indicii elementelor
void step(const Container* const container, int * const indexes, const int start, const int end) {
	if (start < end) {

		// Se sorteaza un element ( indicele din vectorul auxiliar) si se obtine pozitia finala.
		int pos = pivot(container, indexes, start, end);

		// Se reapeleaza pentru a sorta si celelalte elemente ( indici )
		step(container, indexes, start, pos - 1);
		step(container, indexes, pos + 1, end);
	}
}

// Functia de mai sus rescrisa pentru a primi cu un parametru mai putin. ( doar size nu si start )
void sort(const Container* const container, int * const indexes, const int size) {
	step(container, indexes, 0, size - 1);
}

// Verifica daca sortarea avut loc cu succes si afiseaza elementele cu ajutorul vectorului de indici care a fost sortat
void methodShouldSort(const Container* const container, const int * const indexes, const int size) {
	for (int i = 0; i < size - 1; ++i) {

		if (container[indexes[i]].getValue() > container[indexes[i + 1]].getValue()) {
			std::cout << "Elements are not sorted: " << container[indexes[i]].getValue() << ", " << container[indexes[i + 1]].getValue() << std::endl;
			abort();
		}

		std::cout << container[indexes[i]].getValue() << ' ';
	}

	std::cout << container[indexes[size - 1]].getValue() << std::endl;
}

int main()
{
	// Genereaza o samanta intamplatoare
	srand(time(NULL));

	// Vectorul are o dimensiune intamplatoare intre 1 si 100
	const int size = 1 + rand() % 100;
	
	// Vectorul de clase / structuri
	Container* arr = new Container[size];

	// Memoria suplimentara O(n) folosita pentru sortare
	int* const indexes = new int[size];

	std::cout << "Elemente initiale: ";

	for (int i = 0; i < size; ++i) {
		// Se insereaza elemente intamplatoare in vector
		arr[i].setValue(1 + rand() % size);
		std::cout << arr[i].getValue() << ' ';
		indexes[i] = i;
	}

	// Sortez elementele cu ajutorul unui vector auxiliar de indici
	// Algoritmul de sortare utilizat este Quicksort -> O(n ^ 2)
	std::cout << std::endl << "Sortarea indicilor: ";
	sort(arr, indexes, size);
	
	// Se verifica daca sortarea a avut loc cu succes
	methodShouldSort(arr, indexes, size);

	// Eliberarea memoriei
	delete[] indexes;
	delete[] arr;
}