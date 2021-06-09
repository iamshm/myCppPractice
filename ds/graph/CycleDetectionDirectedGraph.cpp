#include <bits/stdc++.h>
using namespace std;
void bfsTopoCycleDirected(int V, vector<int> adj[]) {
    vector<int> indegree(V + 1, 0);
    //calc indegree;
    for (int i = 1; i < V + 1; ++i)
        for ( auto it : adj[i])
            indegree[it]++;

    // push those nodes to queue that have indegree is 0
    queue<int> q;
    for (int i = 1; i < V + 1; i++)
        if (indegree[i] == 0)
            q.push(i);

    // vector<int> topo;
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // topo.push_back(node);
        count++;

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // topological sort works on DAG
    // so if there is a cycle topo sort wont be created
    if (count == V)
        cout << "Cycle Not detected"  << endl;
    else
        cout << "Cycle detected" << endl;
}
bool dfsCheckCycleDirected(int n, vector<int> adj[], vector<bool> &visited, vector<bool> &selfDfs) {
    visited[n] = true;
    selfDfs[n] = true;
    for (auto it : adj[n]) {
        if (!visited[it]) {
            if (dfsCheckCycleDirected(it, adj, visited, selfDfs))
                return true;
        } else if (visited[it] and selfDfs[it])
            return true;
    }
    selfDfs[n] = false;
    return false;
}
void dfsCycleDetectionDirected(int V, vector<int> adj[]) {
    bool found  = false;
    vector<bool> visited(V + 1, false);
    vector<bool> selfDfs(V + 1, false);

    for (int i = 1; i < V + 1; i++) {
        if (!visited[i])
            if (dfsCheckCycleDirected(i, adj, visited, selfDfs)) {
                cout << "Cycle Found" << endl;
                found = true;
                break;
            }
    }
    if (!found) cout << "No Cycle Found" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cerr << u << "->"  << v << "\n";
        adj[u].push_back(v);

    }
    bfsTopoCycleDirected(n, adj);
    // dfsCycleDetectionDirected(n, adj);
    return 0;

}


// Input
// 8 7
// 1 3
// 3 4
// 3 2
// 3 8
// 6 3
// 8 7
// 6 7

// Input
// 8 7
// 1 3
// 3 4
// 3 2
// 3 8
// 6 3
// 8 7
// 7 6