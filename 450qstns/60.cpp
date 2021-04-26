// word Edit problem
// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// https://www.youtube.com/watch?v=We3YDTzNXEk
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x) cout << #x<<" "; cout << x; cout << endl;
#define endl '\n'
#define inf INT_MAX
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

void solve() {
	string s, t;
	cin >> s >> t;
	int m = s.size();
	int n = t.size();
	int dp[m + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	loop(i, 0, n)	{
		dp[0][i] = i;

	}
	loop(i, 0, m)	{
		dp[i][0] = i;
	}
	loop(i, 1, m) {
		loop(j, 1, n) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min (dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1 ;
			}
		}
	}
	cout << dp[m][n] << endl;

	// to backtrack the real operations
	int i = m; int j = n;
	while (true)	{
		if (i == 0 || j == 0)	break;
		if (s[i - 1] == t[j - 1]) {
			i--; j--;
		} else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
			cout << "Edit " << t[j - 1] << " in str2 to " << s[i - 1] << " in s1";
			cout << endl;
			i--; j--;
		} else if (dp[i][j] == dp[i - 1][j] + 1) {
			cout << "del in s1 " << s[i - 1];		cout << endl;
			i--;
		} else {
			cout << "del in s2 " << t[j - 1];		cout << endl;
			j--;
		}
	}
}

int main() {
	fastio();
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