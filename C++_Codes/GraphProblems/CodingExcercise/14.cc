#include <bits/stdc++.h>
#include "../graph.h"
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
        freopen("../error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

bool canFinish(vector<vector<int>> prerequisites,int numCourses) {

  Graph *gr = new Graph(numCourses);

	for(vector<int> edge : prerequisites)
	{
		gr->addEdge(edge[0]+1, edge[1]+1);
	}
    return gr->canFinshGraph();
}

int main() {
  fastio(true);
  int V, E;
  cin >> V >> E;
  vector< vector<int> > prerequisites(E, vector<int>(2, 0));
  for(int i = 0; i < E; ++i) {
  	cin >> prerequisites[i][0] >> prerequisites[i][1];
  }
  if(canFinish(prerequisites, V)) {
    cout << "Yes, We can take the courses." << endl;
  } else {
    cout << "No, We cannot take the courses." << endl;
  }
  return 0;
}

// Sample Input :

// 6 7
// 0 1
// 0 2
// 1 3
// 2 3
// 3 5
// 3 4
// 4 5

// Sample Output :

// Yes, We can take the courses.
