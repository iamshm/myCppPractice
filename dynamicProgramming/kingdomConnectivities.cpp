// No of Path in DAG

// TOposort
//cycle detection

// as it is directed graph
// we need to do topo sort
// then we need to visit the nodes in reverse of topo sort order
// to get nodes in a descendant to ascensor manner
// and we add no of paths

// if u -> v then no of paths from u to dest is
// no of paths from v to dest + no of paths from u to v
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define vi vector<ll>
const int MOD = 1e9;

bool cycle = false;
vector<int> topoSort(vector<int> adj[], int V) {
	vector<int> indegree(V + 1, 0);
	//calc indegree;
	for (int i = 1; i < V + 1; ++i)
		for ( auto it : adj[i])
			indegree[it]++;

	int count = 0;
	queue<int> q;
	for (int i = 1; i < V + 1; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		count++;
		topo.push_back(node);

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}
	if (count != V) cycle = true; //cycle detection
	return topo;
}

int noOfPaths(int src, int dest, vector<int> &topo, vector<int> adj[]) {
	int n = dest;
	vector<int> dp(n + 1, 0);
	dp[dest] = 1;
	for (int i = topo.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < adj[topo[i]].size(); j++)
		{
			dp[topo[i]] += dp[adj[topo[i]][j]];
			dp[topo[i]] %= MOD;
			cerr << topo[i] << "--" << dp[topo[i]] << endl;
		}
	}
	return dp[1];
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> topo = topoSort(adj, n);
	if (cycle) {
		cout << "INFINITE PATHS" << endl;
		return;
	}

	cout << noOfPaths(1, n, topo, adj)	;
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

// 5 5
// 1 2
// 4 2
// 2 3
// 3 4
// 4 5

// 5 5
// 1 2
// 2 4
// 2 3
// 3 4
// 4 5