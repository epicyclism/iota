// iota.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <array>
#include "iota.h"

using alphabet_t = std::array<char, 26> ;
constexpr alphabet_t MakeAlphabet()
{
	alphabet_t rv{};
	epicyclism::iotum_base<char> gen('A');
	for (auto& c : rv)
	{
		c = *gen;
		++gen;
	}

	return rv;
}

constexpr alphabet_t AL = MakeAlphabet();

int main()
{
	using epicyclism::iota;
	for (int i : iota{ 0, 10 })
		std::cout << i << " ";
	std::cout << "\n";

	for (auto c : AL)
		std::cout << c;
	std::cout << "\n";

	return 0;
}
