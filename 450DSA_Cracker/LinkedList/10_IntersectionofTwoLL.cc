#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
        freopen("../../error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Graph {
    vector<int> *adjList;
    int V;
public:
    Graph(int n) {
        this->V = n;
        this->adjList = new vector<int>[V];
    }

    void add_edge(int u, int v) {
        this->adjList[u].push_back(v);
        this->adjList[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        vector<int> distances(V, -1);
        queue<int> Q;
        Q.push(start);
        distances[start] = 0;
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for(int nbr : this->adjList[cur]) {
                if(distances[nbr] == -1) {
                    distances[nbr] = distances[cur] + 6;
                    Q.push(nbr);
                }
            }
        }
        return distances;
    }
};

int main() {
    fastio();
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
