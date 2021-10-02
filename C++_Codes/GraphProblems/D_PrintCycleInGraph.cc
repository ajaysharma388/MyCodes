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
int m, n;

void dfs(int cur, vector<int> &state, vector<int> &par) {
	// Marking as visited and it is stack as state is 1.
	state[cur] = 1;
	for(int nbr : gr[cur]) {
		if(state[nbr] == 0) {
			par[nbr] = cur;
			dfs(nbr, state, par);
		} else if(par[cur] != nbr and state[nbr] == 1) {
			// back edge. from nbr --> cur.
			cout << "we have a backedge from " << nbr << " to " << cur << endl;
			cout << "Cycle : " << nbr ;
			int tmp = cur;
			while(tmp != nbr) {
				cout << " -> " << tmp;
				tmp = par[tmp];
			}
			cout << " -> " << nbr << endl;
		}
	}
	// Masking as Out of stack and visited as state is 2.
	state[cur] = 2;
	return;
}

int main() {
  fastio(true);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
  	int x, y;
  	cin >> x >> y;
  	gr[x].push_back(y);
  	gr[y].push_back(x);
  }
  vector<int> par(n+1, 0);
  vector<int> state(n+1, 0);
  for(int i = 1; i <= n; ++i) {
  	if(state[i] == 0) {
  		dfs(i, state, par);
  	}
  }
  return 0;
}

// Sample Input :

// 5 5
// 1 2
// 2 3
// 2 4
// 4 5
// 3 5

// Sample Output :

// we have a backedge from 2 to 4
// Cycle : 2 -> 4 -> 5 -> 3 -> 2
