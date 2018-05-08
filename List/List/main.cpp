// File: main.cpp
//

#include "stdafx.h"
#include "List.h"

int main()
{
	List::List<std::string> list;

	list.pushEnd("hello,");
	list.pushEnd("world!");
	list.print();

	List::List<std::string> list2(list);
	list2.print();

	system("pause");

	return 0;
}