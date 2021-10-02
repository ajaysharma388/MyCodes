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
	vector<int> parent;
	list<pair<int, int>> edgeList;
public:

	Graph() {
		parent.resize(100000);
		for(int i = 0; i < 100000; ++i) {
		    parent[i] = -1;
		}
	}

	void addEdge(int u, int v) {
		this->edgeList.push_back(make_pair(u, v));
	}

	int findSet(int cur) {
		if(parent[cur] == -1) return cur;
		return findSet(parent[cur]);
	}

	void unionSet(int x, int y) {
		int sx = findSet(x);
		int sy = findSet(y);

		if(sx != sy) { parent[sy] = sx; }
	}
};


vector<bool> DSU(vector<vector<int>>query)
{
	fastio();
	Graph *gr = new Graph();
	vector<bool> result;
	for(vector<int> Q : query) {
		if(Q[0] == 1) {
			gr->unionSet(Q[1], Q[2]);
		} else {
			int sx = gr->findSet(Q[1]);
			int sy = gr->findSet(Q[2]);

			if(sx == sy) { result.push_back(true); }
			else { result.push_back(false); }
		}
	}
    return result;
}
