// Trajan Algorithm
// Articulation Point
// https://www.youtube.com/watch?v=64KK9K4RpKE
// discovery low time disc

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

int V = 5;
void DFStrajanAP(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &AP, vector<int> adj[]) {
	static int time = 0;
	low[u] = disc[u] = time;
	time++;
	int children = 0; // children means subgrapg

	for (auto v : adj[u]) {
		if (disc[v] == -1) {
			children++;
			parent[v] = u;
			DFStrajanAP(v, disc, low, parent, AP, adj);

			low[u] = min(low[u], low[v]);

			if (parent[u] == -1 and children > 1) // case 1: node is root
				AP[u] = true;

			if (parent[u] != -1 and low[v] >= disc[u]) // case 2: non root
				AP[u] = true;
		} else if (v != parent[u]) // back edge
			low[u] = min(low[u], disc[v]);
	}
}

void TrajanArticulationPoint(vector<int> adj[]) {
	vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	vector<bool> AP(V, false);

	for (int i = 0; i < V; ++i)
		if (disc[i] == -1)
			DFStrajanAP(i, disc, low, parent, AP, adj);

	cout << "Articulation Points are: ";
	for (int i = 0 ; i < V; i++)
		if (AP[i])
			cout << i << " ";
}

void solve() {
	vector<int> adj[V];

	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[4].push_back(3);
	adj[3].push_back(4);

	TrajanArticulationPoint(adj);
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

