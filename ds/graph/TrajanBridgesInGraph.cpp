// Bridges in graph
// trajan algorithm
// https://www.youtube.com/watch?v=64KK9K4RpKE&t=1s
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

void trajanDFSbridge(int u , vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &bridges, vector<int> adj[]) {
	static int time = 0;
	disc[u] = low[u] = time;
	time++;

	for (int v : adj[u]) {
		if (disc[v] == -1) {// if the edge is not visited(edge u-v)
			parent[v] = u;
			trajanDFSbridge(v, disc, low, parent, bridges, adj);

			//after traversal while backtracking we find min low time
			low[u] = min(low[u], low[v]); // tree edge(non back edge)

			// if it was not a bridge it would have a
			// edge to ansector and it's min time would be low then its parent
			if (low[v] > disc[u] )
				bridges.push_back({u, v});

		} else if ( v != parent[u]) { // if it is visited and
			// it is not parent then its a backedge
			low[u] = min(low[u], disc[v]);
		}
	}
}

void TrajanFindBridges(vector<int> adj[]) {
	vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	vector<pair<int, int>> bridges;

	for (int i = 0; i < V; ++i)
		if (disc[i] == -1)
			trajanDFSbridge(i, disc, low, parent, bridges, adj);
	cout << "Bridges :\n";
	for (auto it : bridges) {
		cout << it.first << " --> " << it.second << endl;
	}
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

	TrajanFindBridges(adj);
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

