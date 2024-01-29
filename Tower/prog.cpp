#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Box
{
	public:
	Box(int _x, int _y, int _h)
	{
		x = _x;
		y = _y;
		h = _h;
	}
	int x;
	int y;
	int h;
	
	bool operator<=(const Box& b)
	{
		if (x <= b.x && y <= b.y)
			return true;
		if (x <= b.y && y <= b.x)
			return true;
		return false;
	}

	friend std::ostream& operator<< (std::ostream& stream, const Box& b);
};

std::ostream& operator<<(std::ostream& stream, const Box& b)
{
	stream << b.x << "/" << b.y << "/" << b.h << "\n";
	return stream;
}

int getHighestTower(vector<Box>* boxes, vector<int>* highestTower)
{
	int n = (boxes->size());
	int maxHeight = 0;

	//first box:
	
	for (int i=0;i<n;i++){
		highestTower->push_back(boxes->at(i).h);
		maxHeight = max(maxHeight, boxes->at(i).h);
	}

	//other boxes
	for (int upperBoxIndex=1; upperBoxIndex<n;upperBoxIndex++){
		int maxTotalHeightForCurrentBox = highestTower->at(upperBoxIndex);
		for (int previousBoxIndex=0;previousBoxIndex<upperBoxIndex;previousBoxIndex++){
			Box* currentUpperBox = &boxes->at(upperBoxIndex);
			Box* alreadyPutBox = &boxes->at(previousBoxIndex);

			//can we put box on other
			if ((currentUpperBox->x<=alreadyPutBox->x&&currentUpperBox->y<=alreadyPutBox->y)||(currentUpperBox->x<=alreadyPutBox->y&&currentUpperBox->y<=alreadyPutBox->x)){
				maxTotalHeightForCurrentBox=max(highestTower->at(previousBoxIndex)+currentUpperBox->h, maxTotalHeightForCurrentBox);
				
			}
		}
		//update max values
		highestTower->at(upperBoxIndex) = maxTotalHeightForCurrentBox;
		maxHeight = max(maxHeight, maxTotalHeightForCurrentBox);
	}
	return maxHeight;
}

void printBoxes( vector<Box> * boxes)
{
	cout << "\nBoxes:\n";
	for (int i =0; i < boxes -> size(); i++ )
	{
		cout << (*boxes)[i];
	}
}

int main()
{
	vector<Box> boxes; 
	vector<int> highestTower; 
	
	int z,n;
	cin >> z;
	while(z)
	{
		boxes.clear();
		highestTower.clear();
		
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int x,y,h;
			cin >> x >> y >> h;
			boxes.push_back( Box(x,y,h) );
		}
		cout << getHighestTower(&boxes, &highestTower) << "\n";
		z--;
		
	}
	return 1;
}