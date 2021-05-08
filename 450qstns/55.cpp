//longest repeating recurring substring
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

//Approach do lcs but when we find equal char also check they are not of same index
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	string lrs[n + 1][n + 1];
	loop(i, 1, s.size()) {
		loop(j, 1, s.size()) {
			lrs[i][j] = "";
		}
	}
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	loop(i, 1, s.size()) {
		loop(j, 1, s.size()) {
			if (s[i - 1] == s[j - 1] && i != j)
			{	dp[i][j] = 1 + dp[i - 1][j - 1];
				lrs[i][j] = lrs[i - 1][j - 1] + s[i - 1];
			} else
			{	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (lrs[i - 1][j].size() > lrs[i][j - 1].size()) {
					lrs[i][j] = lrs[i - 1][j];
				} else {
					lrs[i][j] = lrs[i][j - 1];
				}
			}
			cout << lrs[i][j] << "-" << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n][n] << "\n" << lrs[n][n];
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