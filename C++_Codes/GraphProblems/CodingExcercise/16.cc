#include <bits/stdc++.h>
#include "header.h"
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
        freopen("../error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}


int main() {
  fastio(true);
  int V, E;
  cin >> V >> E;
  vector<vector<int>> graph(V, vector<int>());
  while(E--) {
  	int u, v;
  	cin >> u >> v;
  	graph[u].push_back(v);
  	graph[v].push_back(u);
  }
  if(isBipartite(graph)) {
  	cout << "Yes, Graph is bipartite." << endl;
  } else {
  	cout << "No, Graph is not bipartite." << endl;
  }
  return 0;
}

// Sample Input :

// 4 4
// 0 1
// 0 3
// 2 1
// 2 3

// Sample Output :

// Yes, Graph is bipartite.
