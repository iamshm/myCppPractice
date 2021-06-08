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
int noOfTrees = 0;
/*-------------------------------------------------------------------------------------*/

int bfs(int node, vector<int> adj[], vector<bool> &visited) {
	noOfTrees++;
	visited[node] = true;
	int len = 1;
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (auto it : adj[node]) {
			if (!visited[it]) {
				len++;
				visited[it] = true;
				q.push(it);
			}
		}
	}
	return len;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int treeLength = 0, maxTreeLen = 0, minTreeLen = INT_MAX;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i < n + 1; ++i)
	{
		if (!visited[i]) {
			int treeLength = bfs(i, adj, visited);

			maxTreeLen = max(maxTreeLen, treeLength);
			minTreeLen = min(minTreeLen, treeLength);
		}
	}
	cout << maxTreeLen << " " << minTreeLen << " " << noOfTrees << endl;
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

