// File: main.cpp
//

#include "stdafx.h"
#include "List.h"

int main()
{
	List::List<int> list;
	list.print();
	list.pushEnd(5);
	list.pushEnd(4);
	list.print();

	std::cout << list.getMaxSize() << std::endl;
	std::cout << UINT_MAX << std::endl;

	int * a = nullptr;
	int * b = a;

	if (b == nullptr) { std::cout << "True!" << std::endl; }
	else { std::cout << "False!" << std::endl; }

	//std::cout << "Press any key to continue . . ." << std::endl;
	//std::cin.get();

	return 0;
}