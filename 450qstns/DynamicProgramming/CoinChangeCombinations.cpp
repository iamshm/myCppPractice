//Coin Chnage
// no of ways without combination

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
	int amount, noOfCOins;
	cin >> amount >> noOfCOins;
	vi a(noOfCOins);
	for (int i = 0; i < noOfCOins; ++i)
		cin >> a[i];

	vector<int> dp(amount + 1, 0);
	dp[0] = 1;

	for (int coin = 0; coin < noOfCOins; ++coin)
		// here a[coin] is value of coin i.e 2,3,5 so on
		for (int j = a[coin]; j <= amount; ++j)
			dp[j] += dp[j - a[coin]];

	cout << dp[amount];
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

