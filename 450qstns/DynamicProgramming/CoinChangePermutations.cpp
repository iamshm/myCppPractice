// COin change permutations

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

	vi coins(noOfCOins);
	for (int i = 0; i < noOfCOins; ++i)
		cin >> coins[i];

	vector<int> dp(amount + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= amount; ++i)
	{

		for (int coin : coins)
		{
			if ( coin <= i)
			{
				int remAmt = i - coin;
				dp[i] += dp[remAmt];
			}

		}
		cerr << i << " " << dp[i] << endl;
	}
	cout << dp[amount];
	for (int i = 0; i < amount + 1; ++i)
	{
		/* code */
		// cerr << dp[i] << endl;
	}

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

