#include <bits/stdc++.h>
using namespace std;

long res = 0;
long val = 0;
long preVal = 0;
void dfs(int u, std::vector<int> adj[], vector<bool> &visited) {
	visited[u] = true;
	for (auto i : adj[u]) {
		if (!visited[i]) {
			dfs(i, adj, visited);
		}
	}
	val++;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;

	cin >> n >> p;

	std::vector<int> adj[n];

	int temp = n;
	while (temp != 0) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		temp--;
	}
	//forming tree

	vector<bool> visited(n, false);//n*n matrix and setting every element to false

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			dfs(i, adj, visited);
			res = res + preVal * val;
			preVal = preVal + val;
			val = 0;


		}
	}
	if (n < p) {
		cout << "0";
	} else
	{	cout << res;
	}
}

