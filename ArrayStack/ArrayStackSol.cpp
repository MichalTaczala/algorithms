
template<class T>
ArrayStack<T>::ArrayStack(string name)
{
	_name = name;
	_size = 0;
}

template <class T>
string ArrayStack<T>::toString() 
{
	string str ="";
	for (int i = 0; i < _size; i++)
	{
		ostringstream stream;
		stream << arraydata[i];
		string converted = stream.str();
		str = str + converted + " ";
	};
	return str;
}

template <class T>
int ArrayStack<T>::getSize() 
{
	return _size;
}

template <class T>
T ArrayStack<T>::getMin() 
{
	return arraydata[min[_size - 1]];
}


template <class T>
bool ArrayStack<T>::isEmpty()
{
	return (_size == 0);
}	


template <class T>
int ArrayStack<T>::push(T item) 
{
	if (getSize() == MAXSIZE) return 0;
	else
	{	
		arraydata[_size] = item;
		if (_size == 0)
		{
			arraydata[_size] = item;
			min[_size] = 0;
		}
		else if (arraydata[_size] <= arraydata[min[_size - 1]])
		{
			min[_size] = _size;
		}
		else
		{
			min[_size] = min[_size-1];
		}
		_size++;
		return 1;
	}	
}


template <class T>
T ArrayStack<T>::pop() 
{
	_size--;
	return arraydata[_size];
}

template <class T>
T ArrayStack<T>::top() 
{
	return arraydata[(_size - 1)];
}

template <class T>
void ArrayStack<T>::clear() 
{
	_size = 0;
}

template <class T>
string ArrayStack<T>::getName() 
{
	return _name;
}

