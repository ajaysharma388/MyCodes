#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Pii pair<int, int>
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

const int N = 1e5+1;
vector<int> gr[N];
int low[N], dis[N], timestamp = 1;
set<Pii> edges;
bool vis[N];


void dfs(int cur, int par, bool vis[]) {
	vis[cur] = true;
	low[cur] = dis[cur] = timestamp++;
	// now iterate over all the nbrs of the current node
	// from it's adjecency list.
	for(int x : gr[cur]) {
		if(!vis[x]) {
			dfs(x, cur, vis);
			low[cur] = min(low[x], low[cur]);

			// check for the bridge.
			if(low[x] > dis[cur]) {
				if(x < cur) { edges.insert({x, cur}); }
				else { edges.insert({cur, x}); }
			}
		}
		else if(par != x) {
			low[cur] = min(low[cur], dis[x]);
		}
	}
}


int main() {
  fastio(true);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edgesList;
  for(int edge = 1; edge <= m; ++edge) {
  	int x, y;
  	cin >> x >> y;
  	edgesList.push_back({x, y});
  	gr[x].push_back(y);
  	gr[y].push_back(x);
  }
  memset(vis, false, N);
  for(int i = 1; i <= n; ++i) {
  	if(!vis[i]) { dfs(i, 0, vis); }
  }

  for(auto edge : edgesList) {
  	int flag = (edges.find(edge) == edges.end()) ? 0 : 1;
  	if(flag) cout << "Unhappy" << endl;
  	else cout << "Happy" << endl;
  }

  return 0;
}

// Sample Input :

// Sample Output :
