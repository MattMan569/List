// File: main.cpp
//

#include "stdafx.h"
#include "List.h"
#include <list>

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

	cout << endl << endl << "Starting l3 removal..." << endl << endl;
	cout << "Size: " << l3.getSize() << endl;
	l3.remove(3);
	cout << "Size: " << l3.getSize() << endl;
	l3.print();
	l3.remove(4);
	cout << "Size: " << l3.getSize() << endl;
	l3.print();
	l3.remove(1);
	cout << "Size: " << l3.getSize() << endl;
	l3.print();
	cout << "Size: " << l3.getSize() << endl;
	l3.remove(2);
	l3.print();
	cout << "Size: " << l3.getSize() << endl;


	//system("pause");

	return 0;
}
