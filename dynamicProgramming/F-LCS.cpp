// https://atcoder.jp/contests/dp/tasks/dp_f
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
string lcs(string a, string b) {
	int n = a.size();
	int m = b.size();
	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i < m + 1; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = n, j = m;
	string ans;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main()
{
	shm();
	string a, b;
	cin >> a >> b;
	cout << lcs(a, b);
}