#include <iostream>
#include <stack>
#include <set>

using namespace std;

class Node {
    public:
        bool isVisited;
        vector<int> edgesTo;
        set<int> ancestors;

        Node() {
            isVisited = false;
            edgesTo = vector<int>();
        }
};

class Edge {
    public:
        int from;
        int to;
        string col;
        Edge(int from, int to, string col) {
            this->from = from;
            this->to = to;
            this->col = col;
        }

        static bool compareEdges(const Edge* a, const Edge* b) {
            if (a->from != b->from) {
            return a->from < b->from;
        }
            return a->to < b->to;
        }
};



class DFS {
    public:
        vector<Node*> nodes;
        vector<Edge*> edges;
        stack<int> stack;
        set<int> ancestors;
        DFS(vector<Node*> nodes) {
            this->nodes = nodes;
            edges = vector<Edge*>();
        }


        void run() {

                for (int f=0;f<nodes.size();f++){
                    if (nodes.at(f)->isVisited) {
                        continue;
                    }
                    Node* currentNode = nodes.at(f);
                currentNode->isVisited = true;
                vector<int> edgesTo = currentNode->edgesTo;
                stack.push(f);
                ancestors.insert(f);
                currentNode->ancestors = ancestors;
                for (int i=0;i<edgesTo.size();i++){
                   
                    runSingle(f, edgesTo.at(i));
                }
                stack.pop();
                ancestors.erase(f);
                }

                
            
            

            sort(edges.begin(), edges.end(), Edge::compareEdges);
            



            for (int i=0;i<edges.size();i++){
                cout << edges.at(i)->from << " " << edges.at(i)->to << " " << edges.at(i)->col << endl;
            }

        }

        void runSingle(int from, int to) {

            if (nodes.at(to)->isVisited) {
                if (ancestors.find(to) != ancestors.end()){
                    edges.push_back(new Edge(from, to, "B"));
                } else if
                (nodes.at(to)->ancestors.find(from) != nodes.at(to)->ancestors.end()){
                    edges.push_back(new Edge(from, to, "F"));}
                 else {
                    edges.push_back(new Edge(from, to, "C"));
                }
            }else{
                
                edges.push_back(new Edge(from, to, "T"));
                Node* currentNode = nodes.at(to);
                currentNode->isVisited = true;
                vector<int> edgesTo = currentNode->edgesTo;
                stack.push(to);
                ancestors.insert(to);
                currentNode->ancestors = ancestors;
                for (int i=0;i<edgesTo.size();i++){
                    runSingle(to, edgesTo.at(i));
                }
                stack.pop();
                ancestors.erase(to);

            }


        }

};



int main() {
    int z;
    cin >> z;
    for (int i = 0; i < z; i++)
    {
        vector<Node*> nodes = vector<Node*>();
        int n,m;
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            Node* node = new Node();
            nodes.push_back(node);
        }
        for (int j = 0; j < m; j++)
        {
            int a,b;
            cin >> a >> b;
            nodes.at(a)->edgesTo.push_back(b);
        }
        DFS dfs = DFS(nodes);
        dfs.run();


    }



    return 0;
}
