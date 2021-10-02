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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n;

void dfs(int x, int y, int **arr) {
	arr[x][y] = 0;
	for(int i = 0; i < 4; ++i) {
		int _x = x + dx[i];
		int _y = y + dy[i];
		if((_x >= 0 and _x < n) and (_y >= 0 and _y < m) and arr[_x][_y] == 1) {
			dfs(_x, _y, arr);
		}
	}
}

int main() {
  fastio(true);
  cin >> n >> m;
  int **arr = new int*[n];

  for(int i = 0; i < n; ++i) {
  	arr[i] = new int[m];
  }

  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < m; ++j) {
  		cin >> arr[i][j];
  	}
  }

  int count = 0;
  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < m; ++j) {
  		if(arr[i][j] == 1) {
  			count += 1;
  			dfs(i, j, arr);
  		}
  	}
  }
  cout << "Number Of Island is : " << count << endl;
  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < m; ++j) {
  		cout << arr[i][j] << " ";
  	}
  	cout << endl;
  }
  return 0;
}


// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// int m, n;

// void dfs(int x, int y, vector<vector<char>> arr) {
// 	arr[x][y] = '0';
// 	for(int i = 0; i < 4; ++i) {
// 		int _x = x + dx[i];
// 		int _y = y + dy[i];
// 		if((_x >= 0 and _x < n) and (_y >= 0 and _y < m) and arr[_x][_y] == '1') {
// 			dfs(_x, _y, arr);
// 		}
// 	}
// }

// int numIslands( vector<vector<char>> arr)
// {
// 	int count = 0;
// 	n = arr.size();
// 	m = arr[0].size();
// 	for(int i = 0; i < n; ++i) {
// 		for(int j = 0; j < m; ++j) {
// 			if(arr[i][j] == '1') {
// 				count += 1;
// 				dfs(i, j, arr);
// 			}
// 		}
// 	}
// 	return count;
// }

// Sample Input :

// 6 5
// 0 0 0 1 1
// 0 1 0 0 0
// 1 1 0 1 1
// 1 0 1 0 1
// 0 0 1 1 0
// 0 0 0 0 0

// Sample Output :

// Number Of Island is : 2
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
