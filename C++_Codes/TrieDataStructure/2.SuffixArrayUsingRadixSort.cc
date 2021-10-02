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

void radix_sort(vector<pair<pair<int, int>, int>> &a) {
  int n = a.size();
  vector<int> a_cnt(n, 0);
  vector<int> pos(n, 0);
  vector<pair<pair<int, int>, int>> a_new(n);
  {
    // Sorting on the bases of second element.
    for(auto x : a) {
      a_cnt[x.first.second] += 1;
    }
    for(int i = 1; i < n; ++i) {
      pos[i] = pos[i-1] + a_cnt[i-1];
    }
    // placing elements.
    for(auto x : a) {
      a_new[pos[x.first.second]] = x;
      pos[x.first.second] += 1;
    }
    a = a_new;
  }
  {
    // Reinitialised The a_cnt.
	  for(int i = 0; i < n; ++i) {
		  a_cnt[i] = 0;
		  pos[i] = 0;
	  }
    // Sorting on the bases of second element.
    for(auto x : a) {
      a_cnt[x.first.first] += 1;
    }
    for(int i = 1; i < n; ++i) {
      pos[i] = pos[i-1] + a_cnt[i-1];
    }
    // placing elements.
    for(auto x : a) {
      a_new[pos[x.first.first]] = x;
      pos[x.first.first] += 1;
    }
    a = a_new;
  }
  return;
}

// Time Complexity Of the Following Code is O(n log n)
// Previously we were using the gernal sorting algorithm due to which that
// algo. takes O(n. log^2(n)) time. since the numbers we have are in [0..n-1]
// range then we can use the radix_sort algotrithm as well. That
// works in O(N). Which uses counting sort algorithm.

// Previously : T(N) = N.logN + logN.(N.log(N))
// Previously : T(N) = N.logN + N.log^2(N)
// Previously : O(N) = N.log^2(N)

// Now : T(N) = N.logN + logN.(N)
// Now : T(N) = N.logN + N.logN
// Now : T(N) = 2.N.logN
// Now : O(N) = N.logN

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
    radix_sort(a);
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
