#include <iostream>
using namespace std;

class Party {
    public:
        int num;
        int votes;
        int seats;
        bool operator>(const Party& p){
            if (votes*(p.seats + 1)>p.votes * (seats + 1)) return true;
            if (p.votes * (seats + 1) > votes*(p.seats + 1)) return false;
            if (num<p.num) return true; else return false;
        }
        // float getQuotient() {
        //     return (float)votes/(seats+1);
        // }
    Party(int num, int votes){
        this->num = num;
        this->votes = votes;
        this->seats = 0;
    }
};


class Heap {
    private:
        vector<Party>* heap;
        int numberOfSeats;
        void downHeap(int idx){
            
            if (2*idx >= heap->size()) return;
            
            if (2*idx + 1 >= heap->size()){
                if (heap->at(2*idx) > heap->at(idx)){
                    swap(heap->at(2*idx), heap->at(idx));
                    return;
                }
                else{ return;}
            }
            bool isFirstBigger=heap->at(2*idx)>heap->at(2*idx+1);

            if (isFirstBigger){
                if (heap->at(2*idx)>heap->at(idx)){
                    swap(heap->at(2*idx), heap->at(idx));
                    downHeap(2*idx);
                    return;
                }
            }
            else{
                if (heap->at(2*idx+1)>heap->at(idx)){
                    swap(heap->at(2*idx+1), heap->at(idx));
                    downHeap(2*idx+1);
                    return;
                }
            }
        }
        void upHeap(int idx) {
            if(idx==1){
                return;
            }
            if (heap->at(idx) > heap->at(idx/2)){
                swap(heap->at(idx), heap->at(idx/2));
                upHeap(idx/2);
                return;
            }
            return;
        }
    public:
        Heap(int numberOfSeat1s) {
            this->heap = new std::vector<Party>; 
            this->heap->push_back(Party(-1, -1));
            this->numberOfSeats = numberOfSeat1s;
        }

        vector<Party>* getHeap(){
            vector<Party>* subVector= new vector<Party>(heap->begin() + 1, heap->end());
            return subVector;
        }

        void insert(Party party){
            heap->push_back(party);
            upHeap(heap->size()-1);
        }

        // int getIndexOfNodeWithTheLowestNumber(){
        //     int startingIdex = 1;
        //     int lowestNumber = INFINITY;
        //     int lowestIdx = 1;


        //     vector<int> potentialIndexes;
        //     potentialIndexes.push_back(startingIdex);
        //     int startingVotes;
        //     while(potentialIndexes.size()>0){
        //         if (potentialIndexes.at(0)>heap->size()){
        //             potentialIndexes.erase(potentialIndexes.begin() + 0);
        //             continue;
        //         }
        //         else if (heap->at(potentialIndexes.at(0)).getQuotient() < startingVotes) {
        //             potentialIndexes.erase(potentialIndexes.begin() + 0);
        //         }else{
        //             if(heap->at(potentialIndexes.at(0)).num<lowestNumber){
        //                 lowestNumber = heap->at(potentialIndexes.at(0)).num;
        //                 lowestIdx = potentialIndexes.at(0);
        //             }
        //         potentialIndexes.push_back(potentialIndexes.at(0)*2);
        //         potentialIndexes.push_back(potentialIndexes.at(0)*2+1);
        //         potentialIndexes.erase(potentialIndexes.begin() + 0);
        //         }
        //     }

        //     return lowestIdx; 
        // }

        void addSeatForParty() {
            int index = 1; //1
            // int index = 1;
            Party* p = &heap->at(index);
            p->seats++;
            downHeap(index);
            return;      
        }

        void calculateSeats() {
            for (int i = 0; i < numberOfSeats; i++)
            {
                addSeatForParty();
            }
            
        }

    
};

//upheap (pos)
//downheap ()

bool compareIndexes(const Party& party1, const Party& party2) {
    return party1.num < party2.num;
}

int main(int argc, char const *argv[])
{

    int numberOfData;
    cin >> numberOfData;
    int numberOfParties;
    int numberOfSeats;

    int currentValueOfVotes;
    for (int i = 0; i < numberOfData; i++)
    {
        cin >> numberOfParties;  
        cin >> numberOfSeats;
        Heap heap = Heap(numberOfSeats);
        int index=0;
        for (int j=0; j< numberOfParties;j++){
            cin >> currentValueOfVotes;
            heap.insert(Party(index, currentValueOfVotes));
            index++;
        }
        heap.calculateSeats();
        vector<Party>* parties = heap.getHeap();
        sort(parties->begin(), parties->end(), compareIndexes);
        for (int i=0; i< parties->size();i++){
            cout << parties->at(i).seats<<" ";
        }
        cout << "\n";
    }
    return 0;
}
