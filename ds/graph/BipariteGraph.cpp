#include <bits/stdc++.h>
using namespace std;

// Biparite detection using dfs
bool dfsCheckBaparite(int node, vector<int> adj[], vector<int> &color) {
	if (color[node] == -1)
		color[node] = 1;
	for (auto it : adj[node]) {
		if (color[it] == -1) {
			color[it] = 1 - color[node];
			if (!dfsCheckBaparite(it, adj, color)) return false;
		} else if (color[it] == color[node])
		{
			return false;
		}
	}
	return true;
}
void dfsBaparite(int V, vector<int> adj[]) {
	bool found = false;
	vector<int> color(V + 1, -1);
	for (int i = 1; i <= V; i++) {
		if (color[i] == -1) {
			if (!dfsCheckBaparite(i, adj, color)) {
				cout << "Not Biparite" << endl;
				found = true;
				break;
			}
		}
	}
	if (!found) cout << "Biparite \n";
}

// Biparite detection using bfs
bool bfsCheckBiparite(int n, int V, vector<int> adj[], vector<int> &color) {
	queue<int> q;
	q.push(n);
	color[n] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : adj[node]) {
			if (color[it] == -1) {
				color[it] = 1 - color[node];
				q.push(it);
			} else if (color[it] == color[node]) {
				return false;
			}
		}
	}
	return true;
}
void bfsBiparite(int V, vector<int> adj[]) {
	bool found = false;
	vector<int> color(V + 1, -1);
	for (int i = 1 ; i <= V ; i++) {
		if (color[i] == -1) {
			if (!bfsCheckBiparite(i, V, adj, color)) {
				cout << "Not Biparite" << endl;
				found = true;
				break;
			}
		}
	}
	if (!found) cout << "Biparite \n";
}
// Input
// 7 6
// 1 3
// 3 4
// 2 3
// 3 6
// 7 6
// 3 7

// Input
// 8 7
// 1 3
// 3 4
// 2 3
// 3 8
// 3 6
// 8 7
// 7 6
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
		adj[v].push_back(u);
	}
	// bfsBiparite(n,adj);
	dfsBaparite(n, adj);
	return 0;

}