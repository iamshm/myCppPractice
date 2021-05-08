// https://atcoder.jp/contests/dp/tasks/dp_a
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
int jump(vector<int> a) {
	int n = a.size();
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++) {
		dp[i] = min((dp[i - 1] + abs(a[i - 1] - a[i])), (dp[i - 2] + abs(a[i - 2] - a[i])));
		// cout << dp[i] << endl;
	}
	return dp[n - 1];
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int cost = jump(a);

	cout << cost;

}