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

const int N = 1e2+1;
vector<int> gr[N];
bool art_pt[N];
int disc[N], low[N], timestamp = 1;


void dfs(int cur, int par, vector<bool> &vis) {
	vis[cur] = true;
	low[cur] = disc[cur] = timestamp++;
	int child = 0;
	// now iterate over all the nodes.
	for(int x : gr[cur]) {
		if(!vis[x]) {
			// simply visit it.
			child += 1;
			dfs(x, cur, vis);
			low[cur] = min(low[cur], low[x]);
			if(par != 0 and low[x] >= disc[cur]) {
				art_pt[cur] = true;
			}
		} else if(par != x) {
			// backedge case.
			low[cur] = min(low[cur], disc[x]);
		}
	}
	if(par == 0 and child > 1) {
		art_pt[cur] = true;
	}
}

vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
	vector<bool> result;
    for(vector<int> edge : edges) {
    	gr[edge[0]].push_back(edge[1]);
    	gr[edge[1]].push_back(edge[0]);
    }
    vector<bool> vis(n+1, false);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, 0, vis);
		}
	}
	for(int q : queries) {
		if(art_pt[q]) {
			result.push_back(true);
		} else {
			result.push_back(false);
		}
	}
	return result;
}

void solve() {
	int n, m;
	cin >> n >> m;
	memset(art_pt, false, sizeof art_pt);
	for(int edge = 1; edge <= m; ++edge) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	vector<bool> vis(n+1, false);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, 0, vis);
		}
	}
	int Q;
	cin >> Q;
	while(Q--) {
		int pt;
		cin >> pt;
		if(art_pt[pt]) {
			cout << "Satisfied " << pt << endl;
		} else {
			cout << "Not Satisfied" << endl;
		}
	}
}

int main() {
  fastio(true);
  solve();
  return 0;
}

// Sample Input :

// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 3 5
// 5
// 1
// 2
// 3
// 4
// 5

// 5 5
// 1 2
// 2 3
// 2 4
// 4 5
// 3 1
// 5
// 1
// 2
// 3
// 4
// 5

// Sample Output :


// Not Satisfied
// Satisfied 2
// Satisfied 3
// Not Satisfied
// Not Satisfied

// Not Satisfied
// Satisfied 2
// Not Satisfied
// Satisfied 4
// Not Satisfied
