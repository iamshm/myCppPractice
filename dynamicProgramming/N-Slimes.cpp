// https://atcoder.jp/contests/dp/tasks/dp_n
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

ll dp[405][405];
ll sum[405][405];
//partitionong at kth slime n calculating mincost of subproblems
ll slimes(vi &a, int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	ll minCost = inf;
	loop(k, i, j - 1) {
		minCost =  min({minCost, slimes(a, i, k) + slimes(a, k + 1, j) + sum[i][j]});
	}
	return dp[i][j] =  minCost;
}
void solve() {
	int n;
	cin >> n;
	vi a(n + 1, 0);
	loop(i, 1, n) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	//below is technique to calculate sum of every sub array
	loop(i, 1, n) {
		loop(j, 1, n) {
			sum[i][j] = a[j] + ((i == j) ? 0 : sum[i][j - 1]);
			// cout << sum[i][j] << " ";
		}
		// cout << endl;
	}
	cout << slimes(a, 1 , n);
	// loop(i, 1, n) {
	// 	loop(j, 1, n) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }
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