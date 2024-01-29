#include <iostream>

using namespace std;

class Edge {
    public:
        int from;
        int to;
        int weight;
    Edge(int from, int to, int weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    bool operator<(const Edge& rhs) const
    {
        return weight < rhs.weight;
    }
};

class Vertex
{
    public:
        int head;
        vector<int> set;
        Vertex(int x){
            this->head = x;
            this->set.clear();
            this->set.push_back(x);
        }
};

class Graph{
    public:
        int n;
        vector<Edge> edges;
        vector<Vertex> vertices;
        Graph(int n, vector<Edge> edges){
            this->n = n;
            this->edges = edges;
            for (int i = 0; i < n; i++)
            {
                vertices.push_back(Vertex(i));
            }
        }
        void addEdge(int x, int y, int w){
            edges.push_back(Edge(x,y,w));
        }
        int minSpanningTree(){
            sort(edges.begin(), edges.end());
            int unionCount = 0;
            int mst = 0;
            for (Edge e : edges)
            {
                if (vertices[e.from].head != vertices[e.to].head){
                    unionCount++;
                    mst += e.weight;

                    int headx = vertices[e.from].head;
                    int heady = vertices[e.to].head;

                    if (vertices[headx].set.size() <= vertices[heady].set.size()){
                        for (int z : vertices[headx].set){
                            vertices[z].head = heady;
                            vertices[heady].set.push_back(z);
                        }
                    }
                    else{
                        for (int z : vertices[heady].set){
                            vertices[z].head = headx;
                            vertices[headx].set.push_back(z);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if ( vertices[vertices[i].head].set.size() < n){
                    return -1;
                }
            }
            return mst;
        }
};


int main(int argc, char const *argv[])
{
    int z;
    cin >> z;
    for (int i = 0; i < z; i++)
    {
        int n,m;
        cin >> n >> m;
        vector<Edge> edges;
        Graph graph = Graph(n, edges);
        for (int j = 0; j < m; j++)
        {

            int a,b,c;
            cin >> a >> b >> c;
            graph.addEdge(a,b,c);
        }
        cout << graph.minSpanningTree()<<"\n";
    }
    return 0;
}




