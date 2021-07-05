// find all shortest path
//Floyd Warshall
// detects negative weight cycle ***
// O(V3)
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

// int V = 6;
#define V 6

void floydWarshall(int graph[V][V]) {

	//creating and filling values in dist array
	int dist[V][V];
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			dist[i][j] = graph[i][j];
		}
	}

	// computing min distance for every vertex
	for (int k = 0; k < V; ++k)
		for (int i = 0 ; i < V; i++)
			for (int j = 0; j < V; j++) {
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
					continue;
				else if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
				// dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][i]);
			}

	// ***
	// if any negative cycle detected
	for (int i = 0 ; i < V; i++)
		if (dist[i][i] < 0)
		{
			cout << " Negative Cycle Detected" << endl;
			return;
		}

	// printing
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; j++)
			cout << i << " to " << j << " = " << dist[i][j] << endl;
		cout << " ---------- " << endl;
	}
}

void solve() {

	int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
		{INT_MAX, 0, 4, 2, 7, INT_MAX},
		{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
		{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}
	};

	floydWarshall(graph);
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

