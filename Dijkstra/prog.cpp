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
class Graph {
    public:
    vector<Node*> allNodes;
    vector<Node*> nodesNotUsed;

    void relaxNode(Node* node) {
        node->isRelaxed=true;
        for (int i=0; i<node->vertices.size();i++){
            int val = node->vertices.at(i)->value;
            int nodeToIdx = node->vertices.at(i)->to;
            
            if (allNodes.at(nodeToIdx)->currentShortest>node->currentShortest+val){
                allNodes.at(nodeToIdx)->currentShortest=node->currentShortest+val;
            }
        }
    }



    int calculate(){
        nodesNotUsed = allNodes;
        allNodes.at(0)->currentShortest=0;
        relaxNode(allNodes.at(0));
        nodesNotUsed.erase(nodesNotUsed.begin()+0);

        while (!nodesNotUsed.empty()){
            int minVal = 1e9;
            int minNodeIdx;
            if (allNodes.at(allNodes.size()-1)->isRelaxed){
                return allNodes.at(allNodes.size()-1)->currentShortest;
            }

            for (int i=0;i<nodesNotUsed.size();i++){
                if (nodesNotUsed.at(i)->currentShortest<minVal){
                    minVal = nodesNotUsed.at(i)->currentShortest;
                    minNodeIdx = i;
                }
            }
            if (minVal==1e9){
                return -1;
            }
            relaxNode(nodesNotUsed.at(minNodeIdx));
            nodesNotUsed.erase(nodesNotUsed.begin()+minNodeIdx);
            
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
