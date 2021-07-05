
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

void solve() {
	int n, m, s;
	cin >> n >> m;
	vector<int> graph[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin >> s;

	vector<int> dist(n + 1, INT_MAX);
	queue<int> q;

	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto it : graph[node]) {
			if (dist[it] > dist[node] + 6)
			{
				dist[it] = dist[node] + 6;
				q.push(it);
			}
		}
	}

	for (int i = 1; i < n + 1; ++i)
	{
		if (i != s) {
			if (dist[i] != INT_MAX) cout << dist[i] << " ";
			else cout << "-1" << " " ;
		}
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int q = 1;
	cin >> q;
	while (q--) {
		solve();
	}

	return 0;
}

// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2