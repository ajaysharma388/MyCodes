#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Graph {
    unordered_map<int, vector<int>> mp;
    public:
    void addEdge(int u, int v, bool bidir = true) {
        mp[u].push_back(v);
        if(bidir) {
            mp[v].push_back(u);
        }
    }
    void printGraph() {
        for(auto p : this->mp) {
            cout << p.first << " : ";
            for(auto nbr : p.second) {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }
    int getCenter() {
        int len = INT_MIN, Center = -1;
        for(auto p : this->mp) {
            int cur = p.first;
            int sz = p.second.size();
            if(sz > len) {
                len = sz;
                Center = cur;
            }
        }
        return Center;
    }
};

int findCenter(vector<vector<int>>edges)
{
    Graph *gr = new Graph();
    for(auto edge : edges) {
        gr->addEdge(edge[0], edge[1]);
    }
    return gr->getCenter();
}
