#include <iostream>
#include <assert.h>
#include <sstream>
#include "SimpleList.h"
#include "OrderedList.h"
#include "BigNumber.h"
#include "Polinom.h"

#define cerinta_p1 "\n(a) adaugarea unui nou element la finalul listei\n"\
			"(b) adaugarea unui nou element la inceputul listei\n"\
			"(c) adaugarea unui nou element in interiorul listei pe o anumita pozitie\n"\
			"(d) afisarea listei\n"\
			"(e) cautarea unui element dupa valoare\n"\
			"(f) cautarea unui element dupa pozitie\n"\
			"(g) stergerea unui element dupa valoare\n"\
			"(h) stergerea unui element dupa pozitie\n"\
			"(i) stergerea intregii liste\n\n"

#define cerinta_p2 "\n(a) adaugarea unui element\n"\
			"(b) afisarea listei\n"\
			"(c) cautarea unui element dupa valoare\n"\
			"(d) cautarea unui element dupa pozitie\n"\
			"(e) eliminarea unui element dupa valoare\n"\
			"(f) eliminarea unui element de pe o pozitie\n"\
			"(g) stergerea intregii liste\n\n"

void p1() {
	SimpleList<int> list;
	int element;

	for (unsigned char option;;) {
		std::cout << cerinta_p1 << "(p1)#"; std::cin >> option;

		if (option == '0') {
			return;
		}

		switch (option) {
		case 'a':
			std::cin >> element;
			list.addLast(element);
			break;
		case 'b':
			std::cin >> element;
			list.addFirst(element);
			break;
		case 'c': {
			std::cout << "Elementul si positia: ";
			int pos; std::cin >> element >> pos;
			list.insert(element, pos);
		}
				  break;
		case 'd':
			std::cout << "Lista este: " << list << std::endl;
			break;
		case 'e':
			std::cin >> element;
			try {
				std::cout << "Elementul se afla pe pozitia: " << list.findByValue(element);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;
		case 'f':
			std::cin >> element;
			try {
				std::cout << "Elementul de pe pozitia " << element << " este: " << list.findByPos(element);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;
		case 'g':
			std::cin >> element;
			list.removeByValue(element);
			break;
		case 'h':
			std::cin >> element;
			list.removeByPos(element);
			break;
		case 'i':
			list.clean();
			break;
		default:
			std::cout << "\nOptiune invalida.\n";
		}
	}
}

void p2() {
	OrderedList<int> list;
	int element;

	for (unsigned char option;;) {
		std::cout << cerinta_p2 << "(p2)#"; std::cin >> option;

		if (option == '0') {
			return;
		}

		switch (option) {
		case 'a':
			std::cin >> element;
			list.add(element);
			break;
		case 'b':
			std::cout << "Lista este: ";
			list.print();
			std::cout << std::endl;
			break;
		case 'c':
			std::cin >> element;
			try {
				std::cout << "Elementul se afla pe pozitia: " << list.findByValue(element);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;
		case 'd':
			std::cin >> element;
			try {
				std::cout << "Elementul de pe pozitia " << element << " este: " << list.findByPos(element);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;
		case 'e':
			std::cin >> element;
			list.removeByValue(element);
			break;
		case 'f':
			std::cin >> element;
			list.removeByPos(element);
			break;
		case 'g':
			list.clean();
			break;
		default:
			std::cout << "\nOptiune invalida.\n";
		}
	}
}

void p3() {
	SimpleList<int> list;
	std::cin >> list;
	std::cout << "Numarul de elemente pozitive este: " << countPos(list) << std::endl;
	std::cout << "Media aritmetica a elementelor negative este: " << avgNeg(list) << std::endl;
}

void p4() {
	SimpleList<double> list;
	std::cin >> list;
	std::cout << "Am adaugat media elementelor consecutive: " << addAvg(list) << std::endl;
}

void p5() {
	// lower, equal, higher
	BigNumber number1, number2;
	std::cin >> number1 >> number2;
	std::cout << number1 + number2;
}

void p6() {
	// Citire si afisare:
	char ch; std::cin.get(ch);
	polinom p, p2; std::cin >> p >> p2;
	std::cout << "Suma dintre polinoamele:\nP1(X) = " << p
		<< "\nP2(X) = " << p2 << "\nEste egala cu: " << p + p2 << std::endl;

	// 6. Inmultirea cu un scalar:
	std::cout << "Scalar: "; int scalar; std::cin >> scalar;
	std::cout << "-> " << p << " inmultit cu " << scalar << " = " << p * scalar << std::endl;

	// 7. Valoare polinomului in x0
	std::cout << "x0 = "; int x0; std::cin >> x0;
	std::cout << "-> " << p << " in punctul " << x0 << " = " << p(x0) << std::endl;
}

void problems() {
	void (*fun[9])() = { p1, p2, p3, p4, p5, p6 };

	for (int problem;;) {
		std::cout << "\n(0 - exit) Alegeti problema 1 - 6\n";
		std::cout << "(main)#"; std::cin >> problem;

		if (problem == 0) {
			return;
		}

		if (problem >= 1 && problem <= 6) {
			fun[problem - 1]();
		}
		else {
			std::cout << "\nAlegere invalida.\n";
		}
	}
}

int main()
{
	problems();
}