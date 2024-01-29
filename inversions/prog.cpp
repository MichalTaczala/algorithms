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


vector<int> mergeSort(vector<int>& perm, int l, int r, int* counter){
	vector<int> sortedL;
	vector<int> sortedR;
	int indexL=0;
	int indexR=0;
	vector<int> combined;
	if (abs(l-r)<=0) {
		combined.push_back(perm.at(l));
		return combined;
	}else{
		sortedL = mergeSort(perm, l, (l+r)/2, counter);
		sortedR = mergeSort(perm, (l+r)/2+1,r,counter);
	}
	int sortedLSize = sortedL.size();
	int sortedRSize = sortedR.size();
	while ((indexL<sortedLSize) && (indexR<sortedRSize)){

		if (sortedL.at(indexL)<sortedR.at(indexR)){
				combined.push_back(sortedL.at(indexL));
					indexL++;
		}else{
			combined.push_back(sortedR.at(indexR));
			indexR++;
			(*counter)+= sortedLSize-indexL;
		}
	}
	while (indexL<sortedLSize){
		combined.push_back(sortedL.at(indexL));
		indexL++;
	}
	while (indexR<sortedRSize){
		combined.push_back(sortedR.at(indexR));
		indexR++;
	}
	return combined;
}


int compute(vector<int>& perm, int n)
{
	int* counter = new int(0);


	mergeSort(perm, 0, n-1, counter);

	return (*counter);
}

int main()
{
	vector<int> perm; 
	
	int z,n,m;
	cin >> z;
	while(z)
	{
		perm.clear();		
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			perm.push_back(x);
		}
		int sol = compute(perm, n);
		cout << sol <<"\n";
		z--;
	}
	return 1;
}