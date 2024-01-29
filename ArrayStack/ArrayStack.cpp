/* This is the only file you can edit */

template<class T>
ArrayStack<T>::ArrayStack(string name)
{
	this->_name = name;
	_size = 0;
}

/* 
Returns a string representation of the stack, consisting of the consecutive items in the stack with the top item at the end of the string
Complexity: O(stack size).
*/
template <class T>
string ArrayStack<T>::toString() 
{

	string str1 = "";
	for (int i=0;i<_size;i++) {
		stringstream s;
    	s << arraydata[i];
		str1+=s.str()+" ";
	}
	return str1;
}

/* 
Gets the size of the stack (the number of elements).
Complexity: O(1).
*/
template <class T>
int ArrayStack<T>::getSize() 
{
	/* write all the necessary code here */
	return _size;
}

/* 
Gets the minimal element in the stack. Called when the stack is non-empty.
Complexity: O(1).
*/
template <class T>
T ArrayStack<T>::getMin() 
{
	return arraydata[min[_size-1]];
}

/* 
Checks if the stack is non-empty.
Complexity: O(1).
*/
template <class T>
bool ArrayStack<T>::isEmpty()
{
	/* write all the necessary code here */
	if (_size==0){
		return true;
	}
	return false;
}	

/* 
Inserts an item into the stack.
Returns 1 if no error occured and 0 otherwise (e.g. lack of memory, stack overflow).
Complexity: O(1).
*/
template <class T>
int ArrayStack<T>::push(T item) 
{
	if (_size<=49) {
		arraydata[_size] = item;
		if (_size == 0 || arraydata[min[_size-1]]>item) {
			min[_size] = _size;;
		}
		else {
			min[_size] = min[_size-1];
		}

		_size++;
		return 1;
	}
	return 0;
	
}


/* 
Deletes a top item from the stack and returns this item.
The method is called only when the stack is non-empty.
Complexity: O(1).
*/
template <class T>
T ArrayStack<T>::pop() 
{
	/* write all the necessary code here */
	_size--;
	return arraydata[_size];
}

/* 
Returns the top item in the stack.
Called only when the stack is non-empty.
Complexity: O(1).
*/
template <class T>
T ArrayStack<T>::top() 
{
	/* write all the necessary code here */
	
	return arraydata[_size-1];
}


/* 
Returns the top item in the stack.
Called only when the stack is non-empty.
Complexity: O(stack size).
*/
template <class T>
void ArrayStack<T>::clear() 
{	
	T topElement = arraydata[_size-1];
	_size=0;
}

/* 
Returns name of the stack.
Complexity: O(1).
*/
template <class T>
string ArrayStack<T>::getName() 
{
	// return "Ala ma kota";
	return _name;
}

