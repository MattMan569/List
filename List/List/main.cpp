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

	system("pause");

	return 0;
}