// Kosaraju SCC
// https://www.youtube.com/watch?v=Rs6DXyWpWrI&t=6s
//Strongly connected components
// step 1: DFS
// step 2: Reversal
// step 3: DFS
// TC: O(3(v+e))

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

int V = 8;

// step1
void dfs1(int u, vector<bool> &visited, stack<int> &stk, vector<int> adj[]) {
	visited[u] = true;

	for (auto v : adj[u]) {
		if (!visited[v])
			dfs1(v, visited, stk, adj);
	}
	stk.push(u);
}
// step 2
void reverseGraph(vector<int> adj[], vector<int> rev[]) {
	for (int i = 0; i < V; ++i)
	{
		for (auto j : adj[i])
			rev[j].push_back(i);
	}
}
// step3
void dfs2(int u, vector<bool> & visited, vector<int> rev[]) {
	cout << u << " ";
	visited[u] = true;
	for (auto v : rev[u]) {
		if (!visited[v])
			dfs2(v, visited, rev);
	}
}

void kosarajuSCC(vector<int> adj[]) {
	stack<int> stk;
	vector<bool> visited(V, false);

	for (int i = 0; i < V; ++i)
		if (!visited[i])
			dfs1(i, visited, stk, adj);

	vector<int> rev[V];
	reverseGraph(adj, rev);

	for (int i = 0; i < V; ++i)
		visited[i] = false;

	while (!stk.empty()) {
		int curr = stk.top();
		stk.pop();

		if (!visited[curr]) {
			dfs2(curr, visited, rev);
			cout << "\n";
		}
	}
}
void solve() {
	vector<int> adj[V];

	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[2].push_back(0);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[6].push_back(4);
	adj[5].push_back(6);
	adj[6].push_back(7);

	kosarajuSCC(adj);
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

