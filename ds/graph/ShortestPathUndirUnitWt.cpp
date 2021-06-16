
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

void shortestPathUndirUnitWeight(int V, vector<int> adj[]) {
	vector<int> dist(V + 1, INT_MAX);
	queue<int> q;
	// src node
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto it : adj[node]) {
			if (dist[it] > dist[node] + 1) {
				dist[it] = dist[node] + 1;
				q.push(it);
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
	vector<int> adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u + 1].push_back(v + 1);
		adj[v + 1].push_back(u + 1);
	}

	shortestPathUndirUnitWeight(n, adj);
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

// 9 11
// 0 1
// 0 3
// 1 3
// 1 2
// 2 6
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 6 8