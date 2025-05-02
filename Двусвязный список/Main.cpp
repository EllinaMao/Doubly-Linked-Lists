#include <iostream>

#include "List.h"

using namespace std;

int main()
{
    List list1;

	char szString[] = "Hello world!";
	cout << szString << endl;

	for (unsigned int i = 0U; i < strlen(szString); ++i)
    {
		list1.AddTail(szString[i]);
    }

    cout << endl << "First list" << endl;
	list1.PrintHead();

	List list2 = list1;

	cout << endl << "Second list" << endl;
	list2.PrintHead();
	
    List list3;
	list3 = list1;

	cout << endl << "Third list" << endl;
	list3.PrintHead();

	cout << endl << "First list" << endl;
	list1.PrintTail();

	list1.RemoveAt(2U);
	list1.PrintHead();

	list1.Insert('?', 0U);
	list1.Insert('?', 4U);
	list1.Insert('?', 4U);
	list1.PrintHead();

    return 0;
}