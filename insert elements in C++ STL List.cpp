// C++ code to demonstrate the working of assign()

#include <iostream>
#include <list> // for list operations
using namespace std;

int main()
{
	// declaring list
	list<int> list1;
	list<int> list2;
	list<int> list3;
	
	// initializing array
	int arr[10] = { 1, 2, 3, 4 };
	
	// using assign() to insert multiple numbers
	// creates 4 occurrences of "2"
	list1.assign(4,2);
	
	// Printing the assigned list
	cout << "The list after inserting multiple elements is : ";
	for (list<int>::iterator i=list1.begin(); i!=list1.end(); i++)
	cout << *i << " ";
	
	cout << endl;
	
	// using assign() to copy elements of list to other
	// assigns 4 occurrences of "2"
	list2.assign(list1.begin(),list1.end());
	
	// Printing the assigned list
	cout << "The list after copying list elements is : ";
	for (list<int>::iterator i=list2.begin(); i!=list2.end(); i++)
	cout << *i << " ";
	
	cout << endl;
	
	// using assign() to copy elements of array to list
	// assigns array elements
	list3.assign(arr,arr+4);
	
	// Printing the assigned list
	cout << "The list after copying array elements is : ";
	for (list<int>::iterator i=list3.begin(); i!=list3.end(); i++)
	cout << *i << " ";
	
	cout << endl;
	
}
