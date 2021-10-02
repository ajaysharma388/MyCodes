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

int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> vertex(n);
    vector<vector<bool>> mark(n, vector<bool>(n, 0));
    int ans = INT_MAX;

    for(auto edge : edges) {
        auto u = --edge[0];
        auto v = --edge[1];
        vertex[u].push_back(v);
        vertex[v].push_back(u);
        mark[u][v] = mark[v][u] = true;
    }

    for(int i = 0; i < n; i++) sort(vertex[i].begin(), vertex[i].end());

    for(int i = 0; i < n; i++)
        for(auto u : vertex[i])
            for(auto v : vertex[i])
                if (i < u && u < v && mark[u][v]) {
                    ans = min(ans, (int)vertex[i].size()  + (int)vertex[u].size() + (int)vertex[v].size() - 6);
                    if (!ans) return ans;
                }
    if (ans == INT_MAX) return -1;
    return ans;
}
