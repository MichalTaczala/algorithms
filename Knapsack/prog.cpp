#include<iostream>
#include<iomanip>
#include<algorithm>
#include <vector>
#include <cstdio>
#include <time.h>
#include <math.h>
using namespace std;

const int MAX = 4000;
int itemSize[MAX]; 
int itemValue[MAX];

//auxiliary function
void printTable(int ** A, int n, int W)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j=0; j<=W ; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "******************************\n";
}

// function allocating memory for amn int table of size (n+1) x (W+1)
void allocate_memory_for_matrix(int** &A, int n, int W)
{
	A = new int* [n+1];
	for(int i=0; i<=n; i++)
	{
		A[i] = new int[W+1];
	}		
}

// function freeing memory taken by a table of size (n+1) x (W+1)
void free_memory_for_matrix(int** A, int n)
{
	for (int i=0;i<=n;i++)
	{
		delete [] A[i];
	}
	delete [] A;
}


void solve(int* s, int * v, int ** A, int n, int W)
{	// s -> item size array
	// v -> item value array
	// W -> max size
	// A[n][w]
	for (int i=0;i<=W;i++){
		A[0][i] = 0;
	}
	for (int currentNumberOfItems=1; currentNumberOfItems<= n;currentNumberOfItems++){
		A[currentNumberOfItems][0]=0;
		for (int currentCapacity=1;currentCapacity<=W;currentCapacity++){
			//we don't take
			A[currentNumberOfItems][currentCapacity] = A[currentNumberOfItems-1][currentCapacity];

			//we take
			if (s[currentNumberOfItems-1] <= currentCapacity && A[currentNumberOfItems][currentCapacity] < v[currentNumberOfItems-1]+A[currentNumberOfItems-1][currentCapacity-s[currentNumberOfItems-1]]){
				A[currentNumberOfItems][currentCapacity] = v[currentNumberOfItems-1]+A[currentNumberOfItems-1][currentCapacity-s[currentNumberOfItems-1]];
			}
		}
	}
}



int main()
{
	int z,n,W;
	cin >> z;
	while(z)
	{		
		cin >> n >> W;
		int ** tab;
		allocate_memory_for_matrix(tab,n,W);
		for(int i=0; i<n; i++)
		{
			cin >> itemSize[i];
			if (itemSize[i]>10) {
        throw std::invalid_argument("size");
			}
		}
		for(int i=0; i<n; i++)
		{
			
			cin >> itemValue[i];
			if (itemValue[i]>10) {
        throw std::invalid_argument("value");
			}
		}
		solve(itemSize,itemValue, tab, n, W);
		cout << tab[n][W] << "\n";
		free_memory_for_matrix(tab,n);
		z--;
	}
		
}
