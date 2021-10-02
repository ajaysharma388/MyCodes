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

// Since we are using gernal sorting algorithm so, sort will
// take N.log(N) time both times.

// Now : T(N) = N.logN + logN.(N.log(N))
// Now : T(N) = N.logN + N.log^2(N)
// Now : O(N) = N.log^2(N)

int main() {
  fastio();
  string s;
  cin >> s;
  s += "$";
  int n = s.size();
  vector<int> p(n), c(n);
  {
    // Iteration for K = 0.
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
      a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for(int i = 1; i < n; ++i) {
      if(a[i-1].first == a[i].first) c[p[i]] = c[p[i-1]];
      else c[p[i]] = c[p[i-1]]+1;
    }
  }
  int k = 0;
  while((1 << k) < n) {
    vector<pair<pair<int, int>, int>> a(n);
    for(int i = 0; i < n; ++i) {
      a[i] = {{c[i], c[(i + (1 << k))%n]}, i};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for(int i = 1; i < n; ++i) {
      if(a[i-1].first == a[i].first) c[p[i]] = c[p[i-1]];
      else c[p[i]] = c[p[i-1]]+1;
    }
    k++;
  }
  for(int i = 0; i < n; ++i) {
    cout << p[i] << " " << s.substr(p[i], n-p[i]) << endl;
  }
  return 0;
}

// Sample Input:

// ababba

// Sample Output:

// 6 $
// 5 a$
// 0 ababba$
// 2 abba$
// 4 ba$
// 1 babba$
// 3 bba$
