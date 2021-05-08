// https://codeforces.com/contest/1509/problem/B
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

ll dp[2005][2005];
int n;
// the intution is int ht last lap it will be max(a[i]) - min(a[i]) \
// for every ith lap it would be max - min in that subarray
ll discrepancy(vi &a, int left, int right) {

	if (dp[left][right] != -1) return dp[left][right];
	if (left == right) return dp[left][right] = 0;
	else
		return dp[left][right] = a[right] - a[left] + min(discrepancy(a, left + 1, right), discrepancy(a, left, right - 1));
}
void solve() {
	cin >> n;
	vi a(n);
	loop(i, 0, n - 1) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	sort(a.begin(), a.end());

	cout << discrepancy(a, 0, n - 1) << endl;
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
