/* You are not allowed to edit this file */
#include <iostream>
#include "Stack.h"

#define MAXSIZE 50

using namespace std;

template <typename T>
class ArrayStack: public Stack<T>
{
	public:  // declaration of the methods of ListStack<T> class
		ArrayStack(string name);  //O(1) 
		int push(T item); //O(1) 
		T pop(); //O(1) 
		T top(); //O(1) 
		T getMin(); //O(1) 
		string toString(); //O(1)
 		void clear();  //O(1)
		int getSize();  
		bool isEmpty(); //O(1)
		string getName(); //O(1)

	private:
		int _size;  // index of the first empty cell (above the top item of the stack)
		string _name; //stack's name
		T arraydata[MAXSIZE]; // stack data table
		int min[MAXSIZE]; // pointer's table to the minimum elements
};	

#include "ArrayStack.cpp"
