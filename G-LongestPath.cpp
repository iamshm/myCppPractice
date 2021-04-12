// https://atcoder.jp/contests/dp/tasks/dp_g
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
#define ll long long
vector<int> adj[100005]; //method to create array of vectors
vector<ll> dp(100005, -1);

// for every vertex we can either stop at that vertex
// or we can vist that , then visit its neighbours
void visit(int vertex) {
	dp[vertex] = 0; // we dont move ahead with this vertex

	//we move ahead with this vertex and visit its neighbour
	for (auto child : adj[vertex]) {
		if (dp[child] == -1)//if unvisited
			visit(child);
		dp[vertex] =  max(dp[vertex], 1 + dp[child]);
	}
}

int n, m;
int main()
{
	shm();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == -1)//if unvisited
			visit(i);
	}
	ll ans = 0;
	for (int i = 1 ; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

