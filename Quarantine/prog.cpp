#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;
class Node {
    public:
    vector<int> to;
    vector<int> from;
    bool isVisited;
    string group;
    Node() {
        isVisited = false;
        group="";
    }
    void addEdge(int a) {
        to.push_back(a);
        isVisited = false;
    }
    void addFrom(int b) {
        from.push_back(b);
    }
    void visit() {
        isVisited = true;
    }
    void unvisit() {
        isVisited = false;
    }
    void setGroup(string group) {
        this->group = group;
    }
};

class Graph {
public:
    int vertices;
    int n;
    vector<Node*>* nodes;
    std::stack<int> stack;

    Graph(int n, vector<Node*>* nodes){
        this->n = n;
        this->nodes = nodes;
    }

    void solveForNode(int node) {
        Node* mynode = nodes->at(node);
        mynode->visit();
        for (int i = 0; i < mynode->to.size(); i++) {
            if (!nodes->at(mynode->to.at(i))->isVisited) {
                solveForNode(mynode->to.at(i));
            }
        }
        stack.push(node);
    }
    int solveForNodeReversed(int node, string group) {
        Node* mynode = nodes->at(node);
        mynode->unvisit();
        mynode->setGroup(group);        
        for (int i = 0; i < mynode->from.size(); i++) {
            if (nodes->at(mynode->from.at(i))->isVisited) {
                solveForNodeReversed(mynode->from.at(i), group);
            }
        }

        return 0;
    }

    void solve(){
        for (int i=0; i<nodes->size(); i++) {
            if (!nodes->at(i)->isVisited)
            solveForNode(i);
        }
        vector<int> sizes;
        int ff = 0;
        while (!stack.empty()) {
            string group = to_string(ff++);
            if (!nodes->at(stack.top())->isVisited) {
                stack.pop();
            }
            else{
                int size = solveForNodeReversed(stack.top(), group);
                sizes.push_back(size);
                stack.pop();
            }
        }
        int min = 1e9;
        vector<string> good;
        vector<string> bad;
        for (int i = 0; i < nodes->size(); i++) {
            for (int a=0;a<nodes->at(i)->to.size();a++) {
                if (nodes->at(i)->group != nodes->at(nodes->at(i)->to.at(a))->group) {
                    bad.push_back(nodes->at(i)->group);
                    break;;
                }
            }
            good.push_back(nodes->at(i)->group);
        }
        std::unordered_map<std::string, int> occurrenceCount;

        for (const auto& value : good) {
            if (std::find(bad.begin(), bad.end(), value) == bad.end()) {
                occurrenceCount[value]++;
            }
        }

        int minCount = std::numeric_limits<int>::max();
        for (const auto& pair : occurrenceCount) {
            minCount = std::min(minCount, pair.second);
        }
        cout << minCount << "\n";
    }

};



int main() {
    int z;
    cin >> z;
    for (int i = 0; i < z; i++) {
        int n,m;
        cin >> n;
        cin >> m;

        vector<Node*>* nodes = new vector<Node*>();
        for (int j = 0; j < n; j++) {
            nodes->push_back(new Node());
        }
        for (int j = 0; j < m; j++) {
            int a,b;
            cin >> a;
            cin >> b;
            if (a == b) {
                continue;
            }
            nodes->at(a)->addEdge(b);
            nodes->at(b)->addFrom(a);
        }
        Graph graph = Graph(n, nodes);
        graph.solve();
    }

    return 0;
}
