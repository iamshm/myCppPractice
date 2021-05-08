// https://atcoder.jp/contests/dp/tasks/dp_j

// Expectation of an event =
// 		probability of that number  * no of times that event occured

// Needs a derivation
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
const int MOD = 1e9 + 7;
#define ll long long int

double dp[305][305][305];
int n;
double sushi(ll one , ll two , ll three) {
	if (one < 0 or two < 0 or three < 0) return 0;
	if (one == 0 and two == 0 and three == 0) return 0;

	if (dp[one][two][three] > -0.9) return dp[one][two][three];
	double exp = (n + one * sushi(one - 1, two, three) + two * sushi(one + 1, two - 1, three) + three * sushi(one, two + 1, three - 1));
	return dp[one][two][three] = exp / (one + two + three);
}

void solve() {
	cin >> n;
	ll one = 0; ll two = 0; ll three = 0;
	for (int i = 0; i < n; ++i)
	{	ll x;
		cin >> x;
		if (x == 1) one++;
		if (x == 2) two++;
		if (x == 3) three++;
	}
	memset(dp, -1, sizeof(dp));

	cout << fixed << setprecision(10) << sushi(one, two , three);
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