#include <iostream>
#include "ArrayStack.h"
using namespace std;
  
int main()
{
	ArrayStack<int> s("S");
	s.push(3);
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push(1);
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push(2);
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push(4);
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.pop();
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.pop();
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.pop();
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push(0);
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
}