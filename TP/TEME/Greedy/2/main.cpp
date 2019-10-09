#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int currentElement, n = 0, maxN = INT_MIN, minP = INT_MAX;
	int signs = 0, product;
	ifstream input;
	input.open("date.in");

	while (input >> currentElement) {
		if (n == 0 && currentElement != 0) {
			product = currentElement;
			n = 1;
		}
		else if (currentElement != 0) {
			product *= currentElement;
		}

		if (currentElement < 0) {
			if (maxN < currentElement) {
				maxN = currentElement;
			}
			signs++;
		}
		else if (minP > currentElement) {
			minP = currentElement;
		}
	}
	if (signs == 0) {
		product = minP;
	}
	else if (signs % 2 == 0) {
		product = product / maxN;
	}

	printf("The minimum product is: %d", product);
	input.close();
}
