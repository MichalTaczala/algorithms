#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
 void printVector(vector<int>& v)
 {
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i]<<" ";
	}
	cout <<"\n";	
 }

int compute(vector<int>& board, int n, int m)
{
	//board = all fields
	//n size of the board
	//m modulo
	/* write all the necessary code here */
	long numberOfSequences=0;
	vector<long> boardsummed;
	for (long i=0; i<n;i++){
		boardsummed.push_back(0);
	}
	boardsummed.at(0)=1;
	for(long i=0; i < n; i++){
		if (board.at(i)==0){
			boardsummed.at(i)=0;
			continue;
		}
		for (long numberOnTheDice = 1 ; numberOnTheDice<=6;numberOnTheDice++){
			if (i+numberOnTheDice<n){
				boardsummed.at(i+numberOnTheDice) += 
				boardsummed.at(i);
			}
		}
	}
	return boardsummed.at(n-1)%m;
}

int main()
{
	vector<int> board; 
	
	int z,n,m;
	cin >> z;
	while(z)
	{
		board.clear();		
		cin >> n >> m;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			board.push_back(x);
		}
		int sol = compute(board, n, m);
		cout << sol <<"\n";
		z--;
	}
	return 1;
}