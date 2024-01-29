/* You are not allowed to edit this file */
/*
	Abstract class Stack (first in, first out).
	Objects of this class (called stacks) maintain the set of elements of generic type T.
	We assume T implements basic comaprison operators (in our tests T is either int ot String). 
*/
#include<iostream>
#include <sstream>  

using namespace std;

template <typename T>
class Stack
{
	public:
		virtual int push(T item) = 0; // inserts an element item to the stack
		virtual T pop() = 0; // returns the top element of the stack and deletes it from the stack
		virtual T top() = 0; // returns the top element 
		virtual string toString() = 0; // returns a string representation of the stack, consisting of consecutive elements in the stack with the top one in the end
		virtual void clear() = 0; // makes the stack empty
		virtual int getSize() = 0; // returns number of elements in the stack
		virtual bool isEmpty() = 0; // tests if the stack is empty
		virtual T getMin() = 0; // returns the minimal element among all elements in the stack
};	