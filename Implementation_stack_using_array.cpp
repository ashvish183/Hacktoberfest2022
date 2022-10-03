#include<iostream>
using namespace std;

// implementation of stack using arrays
// from scratch 
// basic functions of stack --> push, pop, _top, size, isEmpty

class _stack
{
	// private data..
	
	int n1, top = -1;
	int *head = NULL;

public:
	// public data & fucntions..

	// taking stack size using stack constructor
	_stack(int n) {
		head = new int[n]; n1 = n;
	}
	// push the element from the top of stack
	void push(int a) {
		if (top == (n1 - 1)) {cout << "stack overflow\n"; return;}
		top++;
		head[top] = a;
	}
	// pop the top element of stack
	void pop() {
		if (top == -1) {cout << "empty stack\n"; return;}
		top--;
	}
	// return top of stack
	int _top() {
		if (top == -1) { return -1;}
		return head[top];
	}
	// return size of current filled stack
	int size() {
		return top + 1;
	}
	// check stack is empty or not
	bool isEmpty() {
		if (top == -1)return true;
		else return false;
	}
};



int main() {

// random inputs..
	
	_stack s(5);
	int arr[10];

	s.push(23);
	cout<<s._top()<<endl;
	s.push(223);
	cout<<s._top()<<endl;
	s.push(123);
	cout<<s._top()<<endl;
	s.push(3);
	cout<<s._top()<<endl;
	s.push(3);
	s.push(3);
	
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	
	cout << s.isEmpty() << endl;
	cout << s._top() << endl;
	s.push(121);
	cout << s._top() << endl;
	return 0;
	
}
