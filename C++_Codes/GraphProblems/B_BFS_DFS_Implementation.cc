#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false)
{
    if(read)
    {
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


vector<int> bfs(Graph* gr, int v, int src)
{
	vector<int> path;
	vector<bool> visited(v, false);
	queue<int> Q;
	Q.push(src);
	visited[src] = true;
	while(! Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		path.push_back(cur);
		for(int nbr: gr->adjList[cur])
		{
			if(! visited[nbr])
			{
				visited[nbr] = true;
				Q.push(nbr);
			}
		}
	}
	return path;
}


void dfsHealper(Graph *gr, vector<bool> &visited, int cur, vector<int> &path)
{
	if(visited[cur]) return;
	visited[cur] = true;
	path.push_back(cur);
	for(int nbr : gr->adjList[cur])
	{
		dfsHealper(gr, visited, nbr, path);
	}
	return;
}

vector<int> dfs(Graph *gr, int v, int src)
{
	vector<int> path;
	vector<bool> visited(v, false);
	dfsHealper(gr, visited, 0, path);
	return path;
}

int main()
{
  fastio(true);
  int v, e;
  cin >> v >> e;
  Graph *gr = new Graph(v);
  for(int edge = 1; edge <= e; ++edge)
  {
  	int u, v;
  	cin >> u >> v;
  	gr->addEdge(u, v, true);
  }
  gr->printGraph();
  vector<int> bfsPath = bfs(gr, v, 0);
  cout << "bfs path : ";
  for(int e : bfsPath)
  {
  	cout << e << ", ";
  }
  vector<int> dfsPath = dfs(gr, v, 0);
  cout << endl << "dfs path : ";
  for(int e : dfsPath)
  {
  	cout << e << ", ";
  }
  return 0;
}

// Sample Input :

// 7 8
// 0 1
// 1 2
// 2 3
// 3 5
// 5 6
// 4 5
// 0 4
// 3 4


// Sample Output :

// 0 => 1, 4,
// 1 => 0, 2,
// 2 => 1, 3,
// 3 => 2, 5, 4,
// 4 => 5, 0, 3,
// 5 => 3, 6, 4,
// 6 => 5,
// bfs path : 0, 1, 4, 2, 5, 3, 6,
// dfs path : 0, 1, 2, 3, 5, 6, 4,
