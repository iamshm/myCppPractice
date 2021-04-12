#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
#define inf 1e18
const int MOD = 1e9 + 7;

void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

double dp[3005][3005]; // dp(i,j)-wil store j heads in i coins

double coins(vector<double> &prob, int ithCoin, int headsRequired) {
	if (headsRequired == 0) return 1;
	if (ithCoin == 0) return 0;
	if (dp[ithCoin][headsRequired] > -0.9) return dp[ithCoin][headsRequired];
	return dp[ithCoin][headsRequired] = prob[ithCoin] * coins(prob, ithCoin - 1, headsRequired - 1) + (1 - prob[ithCoin]) * coins(prob, ithCoin - 1, headsRequired);
}
int main()
{	clock_t begin = clock(); shm();
	//main prog
	int n;
	cin >> n;
	vector<double> prob(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> prob[i];
	}
	memset(dp, -1, sizeof (dp));
	cout << fixed << setprecision(10) << coins(prob, n, (n + 1) / 2) << endl;


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}