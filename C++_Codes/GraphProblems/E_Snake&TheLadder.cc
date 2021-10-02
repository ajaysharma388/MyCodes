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
vector<int> path;

void dfs(int prev, int cur, vector<int> gr[], vector<int> &dis) {
	if(cur == 36) {
		for(int p : path) {
			cout << p << " ";
		}
		cout << endl;

		return;
	}
	int ans = INT_MAX;
	for(int nbr : gr[cur]) {
		if(dis[nbr] == INT_MAX or dis[nbr] >= dis[cur] + 1) {
			dis[nbr] = dis[cur]+1;
			path.push_back(nbr);
			dfs(cur, nbr, gr, dis);
			path.pop_back();
		}
	}
}

int solve() {
	int n, m;
	cin >> n;
	vector<int> grid[36];
	map<int, int> ladder;
	map<int, int> snake;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		snake[x]= y;
	}
	for(int i = 1; i < 36; ++i) {
		for(int st = 1; st <= 6; ++st) {
			if(ladder.count(st+i)) grid[i].push_back(ladder[st+i]);
			else if(snake.count(st+i)) grid[i].push_back(snake[st+i]);
			else if(st+i <= 36) grid[i].push_back(st+i);
		}
	}

	for(int i = 1; i < 36; ++i) {
		cout << i << " : ";
		for(int nbr : grid[i]) {
			cout << nbr << ", ";
		}
		cout << endl;
	}
	vector<int> dis(37, INT_MAX);
	dis[1] = 0;
	path.push_back(1);
	dfs(0, 1, grid, dis);
	return dis[36];
}

void dfs2(int prev, int cur, vector<int> gr[], vector<int> &dis) {
	if(cur == 100) {
		return;
	}
	int ans = INT_MAX;
	for(int nbr : gr[cur]) {
		if(dis[nbr] == INT_MAX or dis[nbr] >= dis[cur] + 1) {
			dis[nbr] = dis[cur]+1;
			path.push_back(nbr);
			dfs2(cur, nbr, gr, dis);
			path.pop_back();
		}
	}
}

int solve2() {
	int n, m;
	cin >> n;
	vector<int> grid[100];
	map<int, int> ladder;
	map<int, int> snake;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		snake[x]= y;
	}
	for(int i = 1; i < 100; ++i) {
		for(int st = 1; st <= 6; ++st) {
			if(ladder.count(st+i)) grid[i].push_back(ladder[st+i]);
			else if(snake.count(st+i)) grid[i].push_back(snake[st+i]);
			else if(st+i <= 100) grid[i].push_back(st+i);
		}
	}

	vector<int> dis(101, INT_MAX);
	dis[1] = 0;
	path.push_back(1);
	dfs2(0, 1, grid, dis);
	return dis[100];
}

void dfs3(int cur, vector<int> gr[], vector<int> &dis) {
	queue<int> Q;
	Q.push(cur);
	dis[cur] = 0;
	while(!Q.empty()) {
		int c = Q.front(); Q.pop();

		if(c == 100) break;
		for(int nbr : gr[c]) {
			if(dis[nbr] == INT_MAX or dis[nbr] > dis[c] + 1) {
				dis[nbr] = dis[c]+1;
				Q.push(nbr);
			}
		}
	}
}

int solve3() {
	int n, m;
	cin >> n;
	vector<int> grid[100];
	map<int, int> ladder;
	map<int, int> snake;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		snake[x]= y;
	}
	for(int i = 1; i < 100; ++i) {
		for(int st = 1; st <= 6; ++st) {
			if(ladder.count(st+i)) grid[i].push_back(ladder[st+i]);
			else if(snake.count(st+i)) grid[i].push_back(snake[st+i]);
			else if(st+i <= 100) grid[i].push_back(st+i);
		}
	}

	vector<int> dis(101, INT_MAX);
	dfs3(1, grid, dis);
	return dis[100];
}

int main() {
  fastio(true);
  int testcases;
  cin >> testcases;
  for(int test = 1; test <= testcases; ++test)
  {
  	// cout << solve2() << endl;
    cout << "Case #" << test << ": " << solve3() << endl;
  }
  return 0;
}

// Sample Input :

// 3
// 3
// 32 62
// 42 68
// 12 98
// 7
// 95 13
// 97 25
// 93 37
// 79 27
// 75 19
// 49 47
// 67 17
// 4
// 8 52
// 6 80
// 26 42
// 2 72
// 9
// 51 19
// 39 11
// 37 29
// 81 3
// 59 5
// 79 23
// 53 7
// 43 33
// 77 21
// 2
// 2 15
// 14 35
// 1
// 17 13

// Sample Output :
