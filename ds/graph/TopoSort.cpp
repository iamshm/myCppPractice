#include <bits/stdc++.h>
using namespace std;

void bfsTopo(int V, vector<int> adj[]) {
	vector<int> indegree(V + 1, 0);
	//calc indegree;
	for (int i = 1; i < V + 1; ++i)
		for ( auto it : adj[i])
			indegree[it]++;

	// push those nodes to queue that have indegree is 0
	queue<int> q;
	for (int i = 1; i < V + 1; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}
	for (auto it : topo)	cout << it << " ";
}
void dfsTopoSort(int node, stack<int> &st, vector<int> adj[], vector<bool> &visited) {
	visited[node] =  true;
	for (auto it : adj[node])
		if (!visited[it])
			dfsTopoSort(it, st, adj, visited);

	st.push(node);
}
void dfsTopo(int V, vector<int> adj[]) {
	stack<int> st;
	vector<bool> visited(V + 1, false);
	for (int i = 1 ; i <= V; i++) {
		if (!visited[i])
			dfsTopoSort(i, st, adj, visited);
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	// dfsTopo(n, adj);
	bfsTopo(n, adj); // Kahn's Algo Kahns Khans
	return 0;
}
// 6 6
// 5 1
// 6 1
// 6 3
// 3 4
// 4 2
// 5 2
