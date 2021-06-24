// Knapsack

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
	int n, capacity;
	cin >> n >> capacity;
	int wt[n], val[n];
	for (int i = 0; i < n; ++i)
		cin >> val[i];

	for (int i = 0; i < n; ++i)
		cin >> wt[i];

	int dp[n + 1][capacity + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < capacity + 1; ++j)
		{
			if ( j >= wt[i - 1]) {
				// j -wt[i-1] is wt occupied by this item
				if (dp[i - 1][j - wt[i - 1]] + val[i - 1] > dp[i - 1][j]) {
					dp[i][j] = val[i - 1] + dp[i - 1][j - wt[i - 1]];
				} else {
					dp[i][j] = dp[i - 1][j] ;
				}
			} else {
				dp[i][j] = dp[i - 1][j] ;
			}
		}
	}

	cout << dp[n][capacity];
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

