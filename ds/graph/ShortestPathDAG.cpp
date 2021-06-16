
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define vi vector<ll>
const int MOD = 1e9 + 7;

void dfsTopoSort(int node, vector<int> &visited, vector<pair<int, int>> adj[], stack<int> &stk) {
	visited[node] =  1;
	for (auto it : adj[node]) {
		if (!visited[it.first])
		{
			dfsTopoSort(it.first, visited, adj, stk);
		}
	}
	stk.push(node);
	cerr << "node " << node << endl;
	cerr << "stk size" << stk.size() << endl;
}

void shortestPathDAG(int V, int src ,  vector< pair<int, int>> adj[]) {
	// doing topoSort
	vector<int> visited(V + 1, 0);
	stack<int> stk;
	for (int i = 1; i < V + 1; ++i)
	{
		if (!visited[i])
			dfsTopoSort(i, visited, adj, stk);
	}// topoSOrt done

	// traversing according to the toposort order
	vector<int> dist(V + 1, INT_MAX);
	dist[src]  = 0;
	while (!stk.empty()) {
		int node = stk.top();
		stk.pop();
		if (dist[node] != INT_MAX) {
			for (auto it : adj[node]) {
				if (dist[node] + it.second < dist[it.first]) {
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}
	for (int i = 1; i < V + 1; ++i)
	{
		cout << 1 << " to " << i << " is " << dist[i] << endl;
	}
}

void solve() {
	int n, m;
	cin >> n >> m ;
	vector< pair<int, int> > adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u, v , wt;
		cin >> u >> v >> wt;
		adj[u + 1].push_back({v + 1, wt});
	}
	for (int i = 1; i < n + 1; ++i)
	{
		cerr << i << " - >" << adj[i].size() << endl;
	}

	shortestPathDAG(n, 1, adj);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 4 2 2
// 4 5 4
// 2 3 6
// 5 3 1