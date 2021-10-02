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

void count_sort(vector<int> &p, vector<int> &c) {
  int n = p.size();
  vector<int> c_cnt(n, 0);
  // Sorting on the bases of second element.
  for(auto x : c) {
    c_cnt[x] += 1;
  }
  vector<int> pos(n, 0);
  vector<int> p_new(n, 0);
  pos[0] = 0;
  for(int i = 1; i < n; ++i) {
    pos[i] = pos[i-1] + c_cnt[i-1];
  }
  // placing elements.
  for(auto x : p) {
  	int i = c[x];
    p_new[pos[i]] = x;
    pos[i] += 1;
  }
  p = p_new;
  return;
}

bool binSearch(vector<int> &data, string &p) {
  int s = 0, e = data.size() - 1;
  while(s <= e) {
    int mid = (s + e)/2;
    if(data[mid].compare(p) == 0) return true;
    else if(data[mid].compare(p) == 1) s = mid + 1;
    else e = mid - 1;
  }
  return false;
}

// Time Complexity Of the Following Code is O(n log n)
// This code is part of continuous improvement in previous one.
// This Approach is slightly better approach as we have been using
// single counting sort algorithm

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
  	// k -> k + 1
    for(int i = 0; i < n; ++i) {
      p[i] = (p[i] - (1 << k) + n) % n;
    }
    count_sort(p, c);
    vector<int> c_new(n, 0);
    c_new[p[0]] = 0;
    for(int i = 1; i < n; ++i) {
      pair<int, int> prev = {c[p[i - 1]], c[(p[i-1] + (1 << k)) % n]};
      pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      if(prev == cur)
    	c_new[p[i]] = c_new[p[i - 1]];
      else
    	c_new[p[i]] = c_new[p[i - 1]] + 1;
    }
    c = c_new;
    k++;
  }
  vector<string> data(n);
  for(int i = 0; i < n; ++i) {
    data[i] = s.substr(p[i], n-p[i]);
  }
  int Q;
  cin >> Q;
  while(Q--) {
    string p;
    cin >> p;
    if(binSearch(data, p)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
