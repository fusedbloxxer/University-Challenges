#include "AVL.h"


int main()
{
	AVL<std::string> words;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::string word; std::cin >> word;
		words.add(word);
	}

	std::cout << '\n';
	words.rsd(); std::cout << '\n';
	words.srd();
}
