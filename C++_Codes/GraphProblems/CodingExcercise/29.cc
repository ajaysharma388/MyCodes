#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
        freopen("../../error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class DSU {
	int *parent;
	int *rank;
public:
	DSU(int V) {
		parent = new int[V];
		rank = new int[V];
		for(int i = 0; i < V; ++i) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// find using path compression.
	int find(int x) {
		if(parent[x] == -1) return x;
		return parent[x] = find(parent[x]);
	}

	// unite using union by rank.
	void unionSet(int x, int y) {
		int sx = find(x);
		int sy = find(y);

		if(sx == sy) return;
		if(rank[sx] < rank[sy]) {
			parent[sx] = sy;
			rank[sy] += rank[sx];
		} else {
			parent[sy] = sx;
			rank[sx] += rank[sy];
		}
	}
};

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int MST(int n, vector<vector<int>> edges)
{
	sort(edges.begin(), edges.end(), compare);
	DSU s(n);
	int ans = 0;
	for(vector<int> edge : edges) {
		int x = edge[0];
		int y = edge[1];
		int w = edge[2];
		if(s.find(x) != s.find(y)) {
			ans += w;
			s.unionSet(x, y);
		}
	}
	return ans;
}

int main() {
  fastio(true);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  while(m--) {
  	int x, y, w;
  	cin >> x >> y >> w;
  	edges.push_back({x-1, y-1, w});
  }
  cout << MST(n, edges) << endl;
  return 0;
}

// Sample Input :

// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40

// Sample Output :

// 17
