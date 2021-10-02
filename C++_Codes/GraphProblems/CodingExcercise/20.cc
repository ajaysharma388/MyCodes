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

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>> Adj(numCourses);
    vector<int> indeg_cnt(numCourses, 0);
    // Creating The Adjcency list.
    for(auto p : prerequisites) {
        Adj[p[1]].push_back(p[0]);
        indeg_cnt[p[0]] += 1;
    }
    set<pair<int, int>> s;
    for(int i = 0; i < numCourses; ++i) {
        s.insert({indeg_cnt[i], i});
    }

    vector<int> result;
    while(!s.empty()) {
        auto pr = *(s.begin());
        s.erase(pr);
        if(pr.first) {
            result.clear();
            return result;
        }
        int cur = pr.second;
        result.push_back(cur);
        for(auto el : Adj[cur]) {
            if(indeg_cnt[el]) {
                s.erase({indeg_cnt[el], el});
                indeg_cnt[el] -= 1;
                s.insert({indeg_cnt[el], el});
            }
        }
    }
    return result;
}
