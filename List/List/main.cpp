// File: main.cpp
//

#include "stdafx.h"
#include "List.h"

using std::cout;
using std::endl;


int main()
{
	std::vector<int> v1 = { 1,2,3,4 };
	List::List<int> l1(v1);

	std::vector<int> v2 = { 5,6,7,8 };
	List::List<int> l2(v2);

	l1.print();
	cout << endl;
	l2.print();

	List::List<int> l3;
	l3.print();

	l3 = l1;
	cout << endl;
	l3.print();
	l3 = l2;
	cout << endl;
	l3.print();

	l3 = l2 = l1;

	cout << endl;
	l1.print();
	cout << endl;
	l2.print();
	cout << endl;
	l3.print();


	//system("pause");

	return 0;
}
