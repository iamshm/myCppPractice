#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1e18

long long cost = 0;
long nodeCount;

void shm() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


void dfs(int i, std::vector<int> adj[], std::vector<bool> &visited) {
	nodeCount++;
	visited[i] = true;
	for ( auto u : adj[i]) {
		if (!visited[u]) {
			dfs(u, adj, visited);
		}
	}

}

void solve() {
	long long n, m;
	long long costLib, costRoad;
	cin >> n >> m >> costLib >> costRoad;
	int temp = m;
	std::vector<int> adj[100005];//make 2d array of max size 10^5
	while (temp != 0) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		temp--;
	}
	std::vector<bool> visited(100005, false);//make 2d array of max size 10^5
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{	nodeCount = 0;
			dfs(i, adj, visited);
			cost = cost + costLib;
			if (costLib <= costRoad) {
				cost = cost + costLib * (nodeCount - 1);
			} else {
				cost = cost + costRoad * (nodeCount - 1);
			}
		}
	}
	cout << cost << endl;
	for (int i = 1; i <= n; ++i)
	{
		adj[i].clear();
		visited[i] = false;
	}
	cost = 0;//make the cost zero or else it will add up to the next test case
}

int main()
{
	shm();
	int tc = 1;
	cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}
