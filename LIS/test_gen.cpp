#include<iostream>
#include<iomanip>
#include<algorithm>
#include <cstdio>
#include <time.h>
#include <math.h>
using namespace std;

int tab[4000000];

void shuffle(int * t, int n)
{
	for (int i=0; i<n;i++)
	{
		t[i] = i;
	}
	
	for (int i=0; i<n; i++)
	{
		swap(t[i], t[i + rand()%(n-i)]);
	}
	
}


int main()
{
	int n = 4000;
	srand ( time(NULL) );
	
	
	cout << 1 << endl;
	cout << n << endl;
	//cout << n <<" "<< 1999999 << endl;
	shuffle(tab,n);
	
	for (int i=0; i<n; i++)
	{
		cout << tab[i] <<" ";
	}
}
