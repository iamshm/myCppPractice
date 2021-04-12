// https://atcoder.jp/contests/dp/tasks/dp_c
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

int a[100005][4];
int dp[100005][4];
int n;

int vacation ( int day, int task) {
	if (day == n ) return 0;

	if (dp[day][task] != -1) return dp[day][task];

	int maxi = 0 ;
	if (task == 0) {
		maxi = max(maxi, a[day][1] + vacation(day + 1, 1));
		maxi = max(maxi, a[day][2] + vacation(day + 1, 2));
		maxi = max(maxi, a[day][3] + vacation(day + 1, 3));
	} else if (task == 1) {
		maxi = max(maxi, a[day][2] + vacation(day + 1, 2));
		maxi = max(maxi, a[day][3] + vacation(day + 1, 3));
	} else if (task == 2) {
		maxi = max(maxi, a[day][1] + vacation(day + 1, 1));
		maxi = max(maxi, a[day][3] + vacation(day + 1, 3));
	} else {
		maxi = max(maxi, a[day][1] + vacation(day + 1, 1));
		maxi = max(maxi, a[day][2] + vacation(day + 1, 2));
	}
	return dp[day][task] = maxi;
}

int main()
{
	shm();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];

	memset(dp, -1, sizeof dp);

	cout << vacation(0, 0);
}