#ifndef EXERCISE_H
#define EXERCISE_H

#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
    bool **adjList;
    int V;
    Graph(int V) {
        this->V = V;
        this->adjList = new bool*[this->V + 1];
        for(int i = 1; i <= V; ++i) {
            adjList[i] = new bool[this->V + 1];
        }
        for(int i = 1; i <= this->V; ++i) {
            for(int j = 1; j <= this->V; ++j) {
                adjList[i][j] = false;
            }
        }
    }
    void addEdge(int u, int v, bool bidir = true) {
        this->adjList[u][v] = true;
        if(bidir) {
            this->adjList[v][u] = true;
        }
    }
    int getTrios() {
        set<vector<int>> trios;
        for(int i = 1; i <= this->V; ++i) {
            vector<int> nbrs;
            for(int j = 1; j <= this->V; ++j) {
                if(this->adjList[i][j]) {
                    nbrs.push_back(j);
                }
            }
            if(nbrs.size() <= 1) continue;
            for(int x = 0; x < nbrs.size(); ++x) {
                vector<int> posTrio;
                for(int y = x+1; y < nbrs.size(); ++y) {
                    if(this->adjList[nbrs[x]][nbrs[y]]) {
                        posTrio.push_back(i);
                        posTrio.push_back(nbrs[x]);
                        posTrio.push_back(nbrs[y]);
                    }
                }
                sort(posTrio.begin(), posTrio.end());
                trios.insert(posTrio);
            }
        }
        if(trios.size() == 0) return -1;
        for(vector<int> trio : trios) {
            for(int e : trio) { cout << e << " "; }
            cout << endl;
        }
        int cnt = 0;
        for(vector<int> trio : trios) {
            for(int e : trio) {
                int Active = 0;
                for(int x = 1; x <= this->V; ++x) {
                    if(adjList[e][x]) Active += 1;
                }
                cnt += (Active - 2);
            }
        }
        return cnt;
    }

    void printGraph() {
        cout << "    ";
        for(int i = 1; i <= this->V; ++i) {
            cout << i << " ";
        }
        cout << endl;
        for(int i = 1; i <= this->V; ++i) {
            cout << i <<  " : ";
            for(int j = 1; j <= this->V; ++j) {
                if(this->adjList[i][j]) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

class Solution {
public:
    int deg[404];
    int adj[404][404];

    int minTrioDegree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();++i)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            deg[a]++;
            deg[b]++;
            adj[a][b] = 1;
            adj[b][a] = 1;

        }
        int ans = INT_MAX;

        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(adj[i][j])
                {
                    for(int k=j+1;k<=n;++k)
                    {
                        if(adj[i][k] && adj[j][k])
                        {
                            int curr_deg = deg[i]+deg[j]+deg[k]-6;
                            ans = min(ans,curr_deg);
                        }
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

#endif // _EXERCISE_H
