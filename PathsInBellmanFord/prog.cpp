#include <iostream>

using namespace std;


class Edge {
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Node {
public:
    int value;
    vector<Edge*>* edgesTo;
    vector<int> edgesFromIndexes;
    Node() {
        this->value = 1e5;
        edgesTo = new vector<Edge*>();

    }
    void addEdgesTo(Edge* edge) {
        edgesTo->push_back(edge);
    }
};





class BellmanFord {
public:
    vector<Node*>* nodes;
    int maxNumberOfIterations;
    BellmanFord(vector<Node*>* nodes) {
        this->nodes = nodes;
        this->maxNumberOfIterations = nodes->size() - 1;
        this->nodes->at(0)->value = 0;
        this->nodes->at(0)->edgesFromIndexes.push_back(0);
    }

    void solve(){
        bool isNegativeCycle = false;
        for (int i=0; i<=maxNumberOfIterations; i++) {
            bool somethingChanged = false;

            for (int j=0; j<nodes->size(); j++) {
                Node* currNode = nodes->at(j);
                for (int k=0; k<currNode->edgesTo->size(); k++) {
                    Edge* currEdge = currNode->edgesTo->at(k);
                    int newDistance = currNode->value + currEdge->weight;
                    if (newDistance < nodes->at(currEdge->dest)->value && currNode->value != 1e5) {
                        // cout << i << " " << j << " " << k << endl;
                        somethingChanged = true;
                        nodes->at(currEdge->dest)->value = newDistance;
                         nodes->at(currEdge->dest)->edgesFromIndexes = nodes->at(currEdge->src)->edgesFromIndexes;
                         
                         nodes->at(currEdge->dest)->edgesFromIndexes.push_back(currEdge->dest);
                         

               
                    }
                }
                
            }
            if (!somethingChanged) {
                    break;
            }
            if (i == maxNumberOfIterations-1) {
                isNegativeCycle = true;
            }

        }

        string valueToPrint = "";

        if (nodes->at(nodes->size()-1)->value == 1e5) {
            cout <<"I" << endl;
            return;
        } 
        
        for (int i=0; i<nodes->size(); i++) {
            Node* currNode = nodes->at(i);
            if (isNegativeCycle) {
                valueToPrint = "NC";
                cout << valueToPrint << endl;
                return;
            }
        }
        cout << nodes->at(nodes->size()-1)->value << endl;
        for (int i=0; i<nodes->at(nodes->size()-1)->edgesFromIndexes.size(); i++) {

            cout << nodes->at(nodes->size()-1)->edgesFromIndexes.at(i) << " ";
        }
        cout << endl;



    }

};


int main() {
    // Your code here
    int z;
    cin >> z;
    for (int i = 0; i < z; i++) {
        int n,m;
        cin >> n >> m;
        vector<Node*>* nodes = new vector<Node*>();
        for (int j = 0; j < n; j++) {
            Node* node = new Node();
            nodes->push_back(node);
        }
        nodes->at(0)->value = 0;


        vector<Edge*>* edges = new vector<Edge*>();
        for (int j = 0; j < m; j++) {
            int x,y,w;
            cin >> x >> y >> w;
            Edge* e = new Edge(x,y,w);
            
            nodes->at(x)->addEdgesTo(e);
        }
        BellmanFord bf = BellmanFord(nodes);
        bf.solve();
    }

    return 0;
}
