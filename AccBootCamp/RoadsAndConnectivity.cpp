// Dijkstra's Algorithm
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

/*-------------------------------------------------------------------------------------*/
//Floyd Warshall
void allShortestPath(vector<vector<int>> &graph, vector<vector<int>> &dist, int n) {
	for (int k = 1; k < n + 1; ++k)
	{
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
					continue;
				else if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

			}
		}
	}
}

void solve() {
	int n, m , q;
	cin >> n >> m >> q;
	vector<vector<int>> graph(n + 1, vector<int> (n + 1, INT_MAX));
	vector<vector<int>> dist(n + 1, vector<int> (n + 1, INT_MAX));

	for (int i = 0; i < m; ++i)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		graph[u][v] = min(graph[u][v], wt);
		dist[u][v] = graph[u][v];
	}
	for (int i = 0; i < n + 1; ++i)
	{
		dist[i][i] = 0;
	}

	allShortestPath(graph, dist, n);

	for (int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
		if (dist[u][v] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << dist[u][v] << endl;
	}
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

// 5 7 5
// 5 1 5
// 3 2 1
// 4 5 3
// 4 3 5
// 5 3 3
// 4 5 4
// 5 4 5
// 1 2
// 1 3
// 4 4
// 5 1
// 3 2