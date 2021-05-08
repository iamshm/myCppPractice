// https://atcoder.jp/contests/dp/tasks/dp_k
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
const int MOD = 1e9 + 7;
#define ll long long int

ll n, k;
string stones(vector<ll> a, ll k) {
	vector<bool> dp(k + 1, false);
	for (int i = 1; i < k + 1; ++i) {
		for (int val : a) {
			if (val > i) continue;
			if (dp[i - val] == false) dp[i] = true;
		}
	}
	return dp[k] ? "First" : "Second";
}
void solve() {
	cin >> n >> k;
	vector<ll> a(n, 0);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << stones(a, k);
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