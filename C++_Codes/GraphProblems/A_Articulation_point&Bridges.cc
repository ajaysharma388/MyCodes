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

const int N = 1e5;
vector<int> gr[N];
int low[N], dis[N], tmpstmp = 1;
vector<pair<int, int>> bridges;
set<int> articulation;


void dfs(int cur, int par, vector<bool> &vis) {
	vis[cur] = true;
	int child = 0;
	dis[cur] = low[cur] = tmpstmp++;
	for(int x : gr[cur]) {
		if(!vis[x]) {
			child += 1;
			dfs(x, cur, vis);
			// we have done the calculations of the node.
			low[cur] = min(low[cur], low[x]);
			if(low[x] > dis[cur]) {
				bridges.push_back({cur, x});
			}
			if(par != 0 && low[x] >= dis[cur]) {
				articulation.insert(cur);
			}
		} else if(x != par) {
			// visted.
			low[cur] = min(low[cur], dis[x]);
		}
	}
	if(par == 0 && child > 1) {
		articulation.insert(cur);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int edge = 1; edge <= m; ++edge) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	vector<bool> vis(N, false);
	int child = 0;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, 0, vis);
		}
	}
	cout << "Bridges : ";
	for(pair<int, int> p : bridges) {
		cout << "{" << p.first << ", " << p.second << "}, ";
	}
	cout << endl << "Articulation Points : ";
	for(int p : articulation) {
		cout << p << " ";
	}
}

int main() {
  fastio(true);
  solve();
  return 0;
}

// The oprations we are doing for maintainning the low and dis arrays
// for aticulation point and bridge is O(1). So, Time complexity of this
// Code is equivelent to DFS. Which is O(V)|O(N).

// Sample Input :

// 7 8
// 1 2
// 1 3
// 2 3
// 2 4
// 4 5
// 5 6
// 4 7
// 6 7

// 10 11
// 1 2
// 1 3
// 2 3
// 2 8
// 2 4
// 3 10
// 4 5
// 4 7
// 5 9
// 5 6
// 6 7

// Sample Output :

// Bridges : {2, 4},
// Articulation Points : 2 4

// Bridges : {3, 10}, {2, 8}, {5, 9}, {2, 4},
// Articulation Points : 2 3 4 5 
