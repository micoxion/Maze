//get key code here etc.
#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::cin;

void main() {
	std::stack<int> myStack;
	myStack.push(5);
	myStack.push(7);
	cout << myStack.top() << endl;

	myStack.pop();
	cout << myStack.top() << endl;
}