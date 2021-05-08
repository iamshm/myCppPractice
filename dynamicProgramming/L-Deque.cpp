// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
const int MOD = 1e9 + 7;
#define ll long long
int n;
ll a[3005];
ll dp[3005][3005];
ll deque_(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return dp[i][j] = a[i];
	return dp[i][j] = max(a[i] - deque_(i + 1, j), a[j] - deque_(i, j - 1));
}
void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << deque_(0, n - 1);
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