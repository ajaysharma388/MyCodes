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

void dfs(int src, int dest, vector<int> &path, vector<vector<int>> &paths, vector<vector<int>> &graph) {
	// cout << src << " " << dest << endl;
	if(src == dest) {
		vector<int> temp(path.begin(), path.end());
		paths.push_back(path);
		return;
	}

	for(int nbr : graph[src]) {
		path.push_back(nbr);
		dfs(nbr, dest, path, paths, graph);
		path.pop_back();
	}
	return;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    // vector<bool> vis(graph.size(), false);
    vector<vector<int>> paths;
    vector<int> curPath;
    curPath.push_back(0);
    dfs(0, graph.size()-1, curPath, paths, graph);
    return paths;
}

void printAdjList(vector<vector<int>> &graph) {
	for(int i = 0; i < graph.size(); ++i) {
		cout << i << " => ";
		for(int nbr : graph[i]) {\
			cout << nbr << ", ";
		}
		cout << endl;
	}
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
  }
  // printAdjList(graph);
  vector<vector<int>> result = allPathsSourceTarget(graph);
  for(int i = 0; i < result.size(); ++i) {
  	cout << "Path #" << (i+1) << " : ";
  	for(int e : result[i]) {
  		cout << e << " -> ";
  	}
  	cout << endl;
  }
  return 0;
}

// Sample Input :

// 4 5
// 0 1
// 0 2
// 0 3
// 2 3
// 1 3

// 7 13
// 0 1
// 0 2
// 0 5
// 1 3
// 2 3
// 2 4
// 2 5
// 3 7
// 4 3
// 4 7
// 4 6
// 5 6
// 6 7

// Sample Output :

// Path #1 : 0 -> 1 -> 3 ->
// Path #2 : 0 -> 2 -> 3 ->
// Path #3 : 0 -> 3 ->


// Path #1 : 0 -> 1 -> 3 -> 7 ->
// Path #2 : 0 -> 2 -> 3 -> 7 ->
// Path #3 : 0 -> 2 -> 4 -> 3 -> 7 ->
// Path #4 : 0 -> 2 -> 4 -> 7 ->
// Path #5 : 0 -> 2 -> 4 -> 6 -> 7 ->
// Path #6 : 0 -> 2 -> 5 -> 6 -> 7 ->
// Path #7 : 0 -> 5 -> 6 -> 7 -> 
