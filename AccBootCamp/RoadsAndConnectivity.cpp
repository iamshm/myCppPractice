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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------*/

int dijsktraShortestPath(int src , int dest, vector<pair<int, int>> adj[], int V ) {
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	// priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	vector<int> dist(V + 1, INT_MAX);
	priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > minHeap;
	//minHeap -> wt,node
	dist[src] = 0;
	minHeap.push(make_pair(0, src));

	while (!minHeap.empty()) {
		int d = minHeap.top().first;
		int prevNode = minHeap.top().second;
		minHeap.pop();

		for (auto it : adj[prevNode]) {
			// adj -> node,wt
			int nextNode  = it.first;
			int nextDist = it.second;

			if (dist[prevNode] + nextDist < dist[nextNode]) {
				dist[nextNode] = dist[prevNode] + nextDist;
				minHeap.push(make_pair(dist[nextNode], nextNode));
			}
		}
	}
	for (int i = 1; i < V + 1; ++i)
	{
		cerr << dist[i] << " ";
	}
	cerr << endl;
	if (dist[dest] != INT_MAX) return dist[dest];
	else return -1;
}


void solve() {
	int n, m , q;
	cin >> n >> m >> q;
	vector<pair<int, int>> adj[n + 1]; // node,weight

	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}

	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		cout << dijsktraShortestPath(u, v, adj, n) << endl;
	}
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