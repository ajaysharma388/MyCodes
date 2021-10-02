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

int getMaxProfit(int n, vector<int> &prices, int size) {
	if(size == 0) return 0;
	int curAns = INT_MIN;
	// rod cut krna hai. [1...size]
	for(int cut = 1; cut <= size; ++cut)
	{
		if(size-cut >= 0)
		{
			curAns = max(curAns, prices[cut] + getMaxProfit(n, prices, size-cut));
		}
	}
	return curAns;
}

int getMaxProfitTD(int n, vector<int> &prices, int size, vector<int> &dp) {
	if(size == 0) return 0;
	if(dp[size] != -1) return dp[size];
	int curAns = INT_MIN;
	// rod cut krna hai. [1...size]
	for(int cut = 1; cut <= size; ++cut)
	{
		if(size-cut >= 0)
		{
			curAns = max(curAns, prices[cut] + getMaxProfit(n, prices, size-cut));
		}
	}
	dp[size] = curAns;
	return dp[size];
}

int main() {
  fastio(true);
  int n, testcases;
  cin >> n;
  vector<int> prices(n+1, 0);
  vector<int> dp(100, -1);
  for(int i = 1; i <= n; ++i)
  {
  	cin >> prices[i];
  }
  cin >> testcases;
  for(int test = 1; test <= testcases; ++test)
  {
  	int size;
  	cin >> size;
    cout << "Case #" << test << ": " << getMaxProfit(n, prices, size) << endl;
    cout << "Case #" << test << ": " << getMaxProfitTD(n, prices, size, dp) << endl;
  }
  return 0;
}

// Sample Input :

// 10
// 1 5 8 9 10 17 17 20 24 30
// 3
// 7
// 4
// 18

// Sample Output :

// Case #1: 18
// Case #1: 18
// Case #2: 10
// Case #2: 10
// Case #3: 52
// Case #3: 52
