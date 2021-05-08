// https://atcoder.jp/contests/dp/tasks/dp_m
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
const int MOD = 1e9 + 7;
#define ll long long

ll dp[105][100005];
ll candies(vector<int> &a, ll n, ll k) {
	//Base Case
	for (int j = 0; j <= k; ++j) //for 1st Child
		dp[1][j] = (j > a[1]) ? 0 : 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else
				dp[i][j]  = (MOD +  dp[i][j - 1] % MOD + dp[i - 1][j] % MOD - ((j - a[i] - 1 >= 0) ? (dp[i - 1][j - a[i] - 1] % MOD) : 0)) % MOD;
		}
	}
	return dp[n][k];
}
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(dp, 0, sizeof(dp));
	cout << candies(a, n, k);
	// for (int i = 1; i < n + 1; ++i)
	// {
	// 	for (int j = 0; j < k + 1; ++j)
	// 	{
	// 		cout << dp[i][j];
	// 	}
	// 	cout << endl;
	// }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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