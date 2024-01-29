#include <iostream>
#include <vector>

using namespace std;

class Vertice {
    public:
    int to;
    int value;
    Vertice(int to, int value){
        this->to = to;
        this->value = value;
    }
};

class Node {
    public:
    int currentShortest;
    int index;
    vector<Vertice*> vertices;
    bool isRelaxed;
    Node(int index){
        this->index= index;
        this->currentShortest = 1e9; //some big number
        this->isRelaxed=false;
    }
};

    bool compareNodesByValue(const Node* a, const Node* b) {
    return a->currentShortest < b->currentShortest;
}

class Heap {
    public:
    vector<Node*> nodes;
    

    void swap(int idx1, int idx2) {
        Node* currentLowerNode = nodes.at(idx1);
        nodes.at(idx1) = nodes.at(idx2);
        nodes.at(idx2) = currentLowerNode;
    }

    void upHeap(int idx){
        if (idx == 1) return;
        if (nodes.at(idx)->currentShortest<nodes.at(idx/2)->currentShortest){
            swap(idx, idx/2);
            upHeap(idx/2);
        }
        return;
    }
    void downHeap(int idx){
        if (idx*2 >= nodes.size()){
            return;
        }
        if (idx*2 +1 >= nodes.size()){
            if (nodes.at(idx)->currentShortest>nodes.at(2*idx)->currentShortest){
            swap(idx, 2*idx);
            downHeap(2*idx);
            return;
            }
            else{
                return;
            }
        }
        int targetIdx;

        if (nodes.at(2*idx)->currentShortest > nodes.at(2*idx+1)->currentShortest){
            targetIdx = 2*idx+1;
        }
        else{
            targetIdx = 2*idx;
        }
        if (nodes.at(idx)->currentShortest>nodes.at(targetIdx)->currentShortest){
            swap(idx, targetIdx);
            downHeap(targetIdx);
        }
        return;
    }
    public:
        Heap(){
            nodes.push_back(new Node(-1));
        }
        Node* pop(){
            if (nodes.size()==1){
                return NULL;
            }
            Node* elementToReturn = nodes.at(1);
            nodes.at(1) = nodes.at(nodes.size()-1);
            nodes.erase(nodes.begin()+nodes.size()-1);
            downHeap(1);
            return elementToReturn;
        }

        void push(Node* nodeToPush){
            int size = nodes.size();
            nodes.push_back(nodeToPush);
            upHeap(size);
        }

        void decreaseValue(Node* updatedNode) {
            auto idx = find(nodes.begin(), nodes.end(), updatedNode);
            if (idx != nodes.end()){
            upHeap(distance(nodes.begin(), idx));
            return;
            }
            return;
        }
        bool isEmpty() {
            if (nodes.size()==1){
                return true;
            }
            return false;
        }
};


class Graph {
    public:
    vector<Node*> allNodes;
    Heap heap;
    Graph(){
        heap = Heap();
    }

    void relaxNode(Node* node) {
        node->isRelaxed=true;
        for (int i=0; i<node->vertices.size();i++){
            int val = node->vertices.at(i)->value;
            int nodeToIdx = node->vertices.at(i)->to;
            
            if (allNodes.at(nodeToIdx)->currentShortest>node->currentShortest+val){
                allNodes.at(nodeToIdx)->currentShortest=node->currentShortest+val;
                heap.decreaseValue(allNodes.at(nodeToIdx));
            }
        }
    }



    int calculate(){
        allNodes.at(0)->currentShortest=0;
        for (int i=0;i<allNodes.size();i++){
            heap.push(allNodes.at(i));
        }
        while (!heap.isEmpty()){
            if (allNodes.at(allNodes.size()-1)->isRelaxed){
                return allNodes.at(allNodes.size()-1)->currentShortest;
            }
            Node* shortestValueNode = heap.pop();
            if (shortestValueNode->currentShortest == 1e9) return -1;
            relaxNode(shortestValueNode);            
        }
        if (allNodes.at(allNodes.size()-1)->currentShortest!=1e9){
            return allNodes.at(allNodes.size()-1)->currentShortest;
        }
        return -1;
    }
   
};


int main(int argc, char const *argv[])
{
    int numberOfDataSets;
    cin >> numberOfDataSets;
    for (int i = 0; i < numberOfDataSets; i++)
    {
        Graph graph = Graph();
        
        int numberOfVertices;
        int numberOfEdges;
        cin >> numberOfVertices;
        for (int z = 0; z < numberOfVertices; z++)
        {
            graph.allNodes.push_back(new Node(z));
        }
        
        cin >> numberOfEdges;
        for ( int j = 0; j < numberOfEdges; j++)
        {
            vector<int> tmpValues = vector<int>(3,0);
            for (int f= 0; f < 3; f++)
            {
                cin >> tmpValues[f];
            }
            graph.allNodes.at(tmpValues.at(0))->vertices.push_back(new Vertice(tmpValues.at(1), tmpValues.at(2)));
            
        }
        int res = graph.calculate();
        cout << res << "\n";
    }
    return 0;
}
