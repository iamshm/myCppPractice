// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int dp[100005];
int a[100005];

long long jumpFrogK(int n, int k) {

	dp[0] = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j <= i + k; j++) {
			if (j < n)
				dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
		}
	}
	return dp[n - 1];
}
int main()
{
	shm();
	int k, n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {cin >> a[i]; dp[i] = INT_MAX;}

	cout << jumpFrogK(n, k);
}