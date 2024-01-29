#include <iostream>
#include "ArrayStack.h"
using namespace std;
  
int main()
{
	ArrayStack<string> s("S");
	s.push("BB");
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push("AB");
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push("CC");
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
	s.push("AA");
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
	s.push("Ala");
	cout << "Elems in " << s.getName() << ":"<<s.toString() << "\n";	
	cout << "Min in " << s.getName() <<":"<<s.getMin() << "\n";
}