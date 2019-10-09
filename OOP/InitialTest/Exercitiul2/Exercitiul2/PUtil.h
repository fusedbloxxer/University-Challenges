#pragma once
#include <sstream>
#include <string>
#include <regex>
#include <iomanip>
#include "Cerc.h"
#include "Dreptunghi.h"
#include "Patrat.h"
#include "TriunghiDrept.h"
#include "Prajituri.h"

namespace PUtil {
	template<typename T>
	Prajitura<T>* getPrajitura(int index) {
		switch (index) {
		case 1: {
			auto cerc = new Cerc<T>;
			std::cin >> *cerc;
			return cerc;
		}
				break;
		case 2: {
			auto dr = new Dreptunghi<T>;
			std::cin >> *dr;
			return dr;
		}
				break;
		case 3: {
			auto p = new Patrat<T>;
			std::cin >> *p;
			return p;
		}
				break;
		case 4: {
			auto tr = new TriunghiDrept<T>;
			std::cin >> *tr;
			return tr;
		}
				break;
		default:
		{
			throw std::exception{ "INVALID." };
		}
		break;
		}
	}

	template<class T>
	void add(Prajituri<Prajitura<T>>& prajituri) {
		std::cout << "Forma bazei:\n"
			"cerc - 1\n"
			"dreptunghi - 2\n"
			"patrat - 3\n"
			"triunghi - 4\n";

		int index;
		if (std::cin >> index) {
			prajituri.add(getPrajitura<T>(index));
		}
	}

	template<typename T>
	void total(Prajituri<Prajitura<T>>& prajituri) {
		prajituri.total(std::cout);
	}

	template<typename T>
	void remove(Prajituri<Prajitura<T>>& prajituri, int index) {
		prajituri.remove(index);
	}

	template<typename T>
	void operations(Prajituri<Prajitura<T>>& prajituri) {
		std::string operation;

		for (;;) {
			std::cout << "Introduceti operatia: ";
			std::getline(std::cin, operation);

			if (operation == "ADD") {
				add<T>(prajituri);
			}
			else if (operation == "TOTAL") {
				total<T>(prajituri);
			}
			else {
				size_t poz = -1;
				if ((poz = operation.find("REMOVE")) != std::string::npos) {
					operation.erase(poz, 6);

					std::istringstream ss{ operation };

					if (ss >> poz) {
						prajituri.remove(poz);
					}
				}
				else if (operation == "stop") {
					return;
				}
				else {
					std::cerr << "Invalid input. Try again.\n\n";
				}
			}
		}
	}
}
