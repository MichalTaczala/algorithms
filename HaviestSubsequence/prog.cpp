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

int compute(vector<int>& seq, int n)
{
	vector<int> sumValues;
	for (int i=0;i<n;i++){
		if (i==0){
			sumValues.push_back(seq.at(0));
			continue;
		}
		if (i==1) {
			sumValues.push_back(max(seq.at(0), seq.at(1)));
			continue;
		}
		if (i==2) {
			if (sumValues.at(i-2)+seq.at(i)> sumValues.at(i-1)){
				sumValues.push_back(sumValues.at(i-2)+seq.at(i));
				continue;
			}
			else{
				sumValues.push_back(sumValues.at(i-1));
				continue;
			}
		}
		if (seq.at(i)+sumValues.at(i-2)>sumValues.at(i-1)){
			sumValues.push_back(seq.at(i)+sumValues.at(i-2));
		}else{
			sumValues.push_back(sumValues.at(i-1));
		}
	}
	return sumValues.at(n-1);
}

int main()
{
	vector<int> seq;	
	int z,n;
	cin >> z;
	while(z)
	{
		seq.clear();		
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			seq.push_back(x);
		}
		int sol = compute(seq, n);
		cout << sol <<"\n";
		z--;
	}
	return 1;
}