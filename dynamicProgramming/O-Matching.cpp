// https://atcoder.jp/contests/dp/tasks/dp_o
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

ll dp[22][(1 << 22)];
ll matching(vector<vector<int>> &compat, int i, int mask, int n) {
	if (i == n + 1)
		if (mask == 0) return 1;
	return 0;
	if (dp[i][mask] != -1) return dp[i][mask];

	ll ans = 0;
	loop(women, 0, n - 1) {
		bool available = (((1 << i) & (mask)) == 0 )? 0 : 1;
		if (available and compat[i][women + 1] == 1) {
			ans = ((ans % MOD) + (matching(compat, i + 1, mask ^ (1 << women), n) % MOD)) % MOD;
		}
	}
	return dp[i][mask] = ans;
}
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> compat(n + 1, vector<int>(n + 1));
	memset(dp, -1, sizeof(dp));
	loop(i, 1, n)
		loop(j, 1, n)
			cin >> compat[i][j];
	cout << matching(compat, 1, ((1 << n) - 1), n);
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