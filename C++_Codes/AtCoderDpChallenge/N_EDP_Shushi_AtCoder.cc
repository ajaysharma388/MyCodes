#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define pb push_back
#define MOD 1000000007

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

double dp[301][301][301];
double solve(int x, int y, int z, int &n) {
  if(x < 0 or y < 0 or z < 0) return 0;
  if(x == 0 and y == 0 and z == 0) return 0;
  if(dp[x][y][z] > -0.9) return dp[x][y][z];
  double exp = n + x*solve(x-1, y, z, n) + y*solve(x+1, y-1, z, n) + z*solve(x, y+1, z-1, n);
  return dp[x][y][z] = exp/(x + y + z);
}

int32_t main() {
  fastio();
  int n, x;
  cin >> n;
  memset(dp, -1, sizeof dp);
  int one = 0, two = 0, three = 0;
  for(int i = 0; i < n; ++i) {
    cin >> x;
    if(x == 1) one += 1;
    else if(x == 2) two += 1;
    else three += 1;
  }
  cout << fixed << setprecision(10) << solve(one, two, three, n) << endl;
}

// Sample Input :

// 10
// 1 3 2 3 3 2 3 2 1 3

// Sample Output :

// 54.48064457488221
// https://ide.codingblocks.com/s/468714

//
// #include <iostream>
// using namespace std;
//
// #define int long long int
//
// int rollDice() {
//     return (rand() % 6 + 1);
// }
//
// int getSix() {
//     if((rand() % 6 + 1) == 6)
//         return 1;
//     return 1 + getSix();
// }
//
// bool Done(vector<int> &susyDish, int n) {
//     for(int i = 0; i < n; ++i) {
//         if(susyDish[i] == 1) {
//             return 0;
//         }
//     }
//     return 1;
// }
//
// int experiment(vector<int> &susyDish, int n) {
//     if(Done(susyDish, n)) return 0;
//     int idx = (rand() % n) + 1;
//     susyDish[idx] = max(0, susyDish[idx] - 1);
//     return 1 + experiment(susyDish, n);
// }
//
// int32_t main() {
//     int sum = 0;
//     int runs = 100000;
//     for(int i = 0; i < runs; ++i) {
//         sum += getSix();
//     }
//     cout << (float) sum/runs << endl;
//     return 0;
// }
