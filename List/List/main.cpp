// File: main.cpp
//

#include "stdafx.h"
#include "List.h"
#include <list>

using std::cout;
using std::endl;


int main()
{
	//std::vector<int> v1 = { 1,1,1,2,3,3,4,5,5,5,6,7,7,8,8,8 };
	std::vector<int> v1 = { 1,1,1,2,2,4,5,3,3,6,6,6,6,6,7,8,9,0,0,0,0 };
	List::List<int> l1(v1);

	l1.print();
	cout << "Nodes removed: " << l1.removeDuplicates() << endl;
	l1.print();


	//system("pause");

	return 0;
}
