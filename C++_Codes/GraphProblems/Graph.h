#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	set<int> *adjList;
	int V;

	// default contructor for the class.
	Graph () {}

	// parameterised constructor for the graph.
	Graph(const int V)
	{
		this->V = V;
		this->adjList = new set<int>[V+1];
	}

	// Method to add the node in the adjecency list.
	void addEdge (int u, int v, bool bidir = false)
	{
		this->adjList[u].insert(v);
		if(bidir)
		{
			this->adjList[v].insert(u);
		}
	}

	// printing the adjecency list.
	void printGraph()
	{
		for(int i = 1; i <= this->V; ++i)
		{
			cout << i << " => ";
			for(int nbr : this->adjList[i])
			{
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

	bool dfsHelper(int src, int parent, bool *visited) {
		visited[src] = true;
		for(int nbr : this->adjList[src])
		{
			if(!visited[nbr])
			{
				//we will visit it.
				bool cyclefromnbr = dfsHelper(nbr, src, visited);
				if(cyclefromnbr) return true;
			}
			else if(nbr != parent)
			{
				return true;
			}
		}
		return false;
	}

	bool checkCycle() {
		bool *visited = new bool[this->V+1]();
		for(int i = 1; i <= this->V; ++i) {
			visited[i] = false;
		}
		for(int i = 1; i <= this->V; ++i) {
		    if(!visited[i] and dfsHelper(i, -1, visited)) return true;
		}
		return false;
	}

	bool dfsHelperDir(int src, bool *visited, bool *inStack) {
		visited[src] = true;
		inStack[src] = true;

		for(int nbr : this->adjList[src])
		{
			if(!visited[nbr])
			{
				//we will visit it.
				bool cyclefromnbr = dfsHelperDir(nbr, visited, inStack);
				if(cyclefromnbr) return true;
			}
			else if(inStack[nbr])
			{
				return true;
			}
		}
		inStack[src] = false;
		return false;
	}

	bool checkCycleDirectedGR() {
		bool *visited = new bool[this->V+1]();
		bool *inStack = new bool[this->V+1]();
		for(int i = 1; i <= this->V; ++i) {
			visited[i] = false;
			inStack[i] = false;
		}
		for(int i = 1; i <= this->V; ++i) {
		    if(!visited[i] and dfsHelperDir(i, visited, inStack)) return true;
		}
		return false;
	}

	bool canFinshGraph() {
		int *indegree = new int[this->V+1]();
		for(int i = 1; i <= this->V; ++i) {
			indegree[i] = 0;
		}
		for(int i = 1; i <= this->V; ++i)
		{
			for(int nbr : this->adjList[i])
			{
				indegree[nbr] += 1;
			}
		}
		queue<int> Q;
		for(int i = 1; i <= this->V; ++i)
		{
			if(indegree[i] == 0) {
				Q.push(i);
			}
		}
		if(Q.empty()) return false;

		while(! Q.empty() ) {
			int cur = Q.front();
			Q.pop();
			for(int nbr : this->adjList[cur]) {
				indegree[nbr] -= 1;
				if(indegree[nbr] == 0) { Q.push(nbr); }
			}
		}

		for(int i = 1; i <= this->V; ++i) {
			if(indegree[i] != 0) { return false; }
		}
		return true;
	}

	bool dfsBipartiteHelper(int cur, vector<int> &visited, int color) {
		visited[cur] = color;

		for(int nbr : this->adjList[cur]) {
			if(visited[nbr] == 0) {
				bool isBipartite = dfsBipartiteHelper(nbr, visited, 3-color);
				if(!isBipartite) {
					return false;
				}
			} else if(color == visited[nbr]) {
				return false;
			}
		}
		return true;
	}

	bool isBipartiteGraph() {
		vector<int> visited(this->V+1, 0);
		for(int i = 1; i <= this->V; ++i) {
			if(visited[i] && !dfsBipartiteHelper(i, visited, 1))
				return false;
		}
		return true;
	}
};
