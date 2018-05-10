// File: main.cpp
//

#include "stdafx.h"
#include "List.h"


int main()
{
	List::List<std::string> list;

	list.pushEnd("hello,");
	list.pushEnd("world!");
	list.pushEnd(" ");
	list.pushEnd("bye!");
	list.pushStart("...");
	list.print();

	List::List<std::string> list2(list);
	list2.print();
	list.print();

	std::cout << list.getMaxSize() << " " << list2.getMaxSize() << std::endl;

	//system("pause");

	return 0;
}