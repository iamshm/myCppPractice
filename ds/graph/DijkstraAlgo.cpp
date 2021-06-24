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

void dijsktraShortestPath(int src, vector<pair<int, int>> adj[], int V ) {
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	// priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	vector<int> dist(V + 1, INT_MAX);
	priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > pq;
	//pq -> wt,node
	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int d = pq.top().first;
		int prevNode = pq.top().second;
		pq.pop();

		// adj -> node,wt
		// pq -> wt,node
		for (auto it : adj[prevNode]) {
			int nextNode  = it.first; // of adjacency matrix
			int nextDist = it.second;
			if (dist[nextNode] > dist[prevNode] + nextDist) {
				dist[nextNode] = dist[prevNode] + nextDist;
				pq.push(make_pair(dist[nextNode], nextNode));
			}
		}
	}
	for (int i = 1; i < V + 1; ++i)
	{
		cout << dist[i] << " ";
	}
	cerr << endl;
	// if (dist[dest] != INT_MAX) return dist[dest];
	// else return -1;
}


void solve() {
	int n, m , src;
	cin >> n >> m ;
	vector<pair<int, int>> adj[n + 1]; // node,weight

	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	cin >> src;

	// for (int i = 0; i < q; i++) {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	cout << dijsktraShortestPath(u, v, adj, n) << endl;
	// }
	dijsktraShortestPath(src, adj, n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();
	clock_t begin = clock();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}

// 5 6
// 1 2 2
// 1 4 1
// 4 3 3
// 2 3 4
// 2 5 5
// 3 5 1
// 1
