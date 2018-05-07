// File: main.cpp
//

#include "stdafx.h"
#include "List.h"

int main()
{
	List::List<int> list;

	std::cout << list.getMaxSize() << std::endl;
	std::cout << UINT_MAX << std::endl;



	std::cout << "Press any key to continue . . ." << std::endl;
	std::cin.get();

	return 0;
}