// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

ll a , b;

void solve() {
	cin >> a >> b;
	ll dp[a + 1][b + 1];
	memset(dp, 0, sizeof(dp));
	ll ans = 0;
	for (ll i = 1; i <= a; i++) {
		for (ll j = 1; j <= b; j++) {
			if ( (dp[i][j] == 0 || dp[j][i] == 0) and (i != j))
				dp[i][j] = __gcd(i, j);
			ans = max(ans, max(dp[i][j], dp[i][j]));
		}
	}
	cout << ans;
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