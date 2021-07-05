
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
int n;
int specialNodes(vector<int> graph[]) {
	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		for (auto node : graph[i])
			if (graph[node].size() == 0)
				vis[i] = 1;


	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i])
			ans++;
	}
	return ans;
}
void solve() {
	int  m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	vector<int> bdj[n + 1];
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		bdj[y].push_back(x);
	}
	cout << max(specialNodes(adj), specialNodes(bdj));
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
		return 0;
	}
}
// 5 6
// 1 2
// 1 3
// 1 4
// 2 5
// 3 5
// 3 5