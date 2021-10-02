// Problem Coding Exercise 12 : Cycle Detection in undirected
// graph for this we will use a Graph.h header file.

#include <bits/stdc++.h>
#include "graph.h"
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

bool solve(int n, vector<vector<int>> &edges) {
	Graph *gr = new Graph(n);
	for(vector<int> edge : edges) {
	  	gr->addEdge(edge[0], edge[1], true);
  	}
  	gr->printGraph();
    if(gr->checkCycle()) {
        return true;
    }
	return false;
}

int main() {
  fastio(true);
  int V, E;
  cin >> V >> E;
  vector< vector<int> > edges(E, vector<int>(2, 0));
  for(int i = 0; i < E; ++i) {
  	cin >> edges[i][0] >> edges[i][1];
  }
  if(solve(V, edges)) {
    cout << "cycle is present" << endl;
  } else {
    cout << "cycle is not present" << endl;
  }
  return 0;
}

// Sample Input :

// 5 4
// 1 2
// 1 3
// 1 4
// 4 5


// Sample Output :


// 1 => 2, 3, 4,
// 2 => 1,
// 3 => 1,
// 4 => 1, 5,
// 5 => 4,
// cycle is not present
