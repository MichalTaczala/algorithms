#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<algorithm>

using namespace std;

class DS
{
	vector<int> sorted;
	public:
		DS(vector<int>& inval); //should work in time O(n)
		~DS();
		void downHeap(int idx, int val, int currSize);
		bool compare(int k, int x); // should work in time O(k)		
};		

DS::DS(vector<int>& inval)
{
	//counting sort in O(n)
	long max = 0;
    for (int i = 0; i < inval.size(); i++) {
        if (max < inval.at(i)) {
            max = inval.at(i);
        }
    }
	long ar [max];

	for (long i=0;i<=max;i++){
		ar[i]=0; //initialize with 0s
	}
	for (int i=0;i<inval.size();i++){
		ar[inval.at(i)]++;
	}
	for (long i=max;i>=0;i--){
		sorted.push_back(i);
		sorted.insert(sorted.end(), ar[i],i);
	}
	// for (int i=0; i<sorted.size();i++){
	// 	cout<<sorted.at(i);
	// }
};

DS::~DS()
{
	/* write all the necessary code here*/
};


bool DS::compare(int k, int x)
{
	//comparing for counting sort
	int counter = 0;
	for (int i=sorted.size()-1;i>=0;i--){
		if (sorted.at(i)>=x){
			counter++;
		}else{
			break;
		}
		if (counter==k){
			return true;
		}
		
	}
	return false;
}

int main()
{
	int z;
	cin >> z;
	while(z)
	{
		int n,q;
		vector<int> val;
		cin >> n >> q;
		for(int i =1; i<=n; i++)
		{
			int x;
			cin >> x;
			val.push_back(x);
		}
		DS ds = DS(val);		
		//ds.print();
		while(q)
		{
			int x,k;
			cin >> k >> x;
			if (ds.compare(k,x))
				cout << "YES\n";
			else
				cout <<"NO\n";
			q--;
		}
		z--;
	}
}