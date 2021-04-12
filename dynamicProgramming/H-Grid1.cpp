// https://atcoder.jp/contests/dp/tasks/dp_h
#include <bits/stdc++.h>

#include <chrono>
using namespace std::chrono;
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
const int MOD = 1e9 + 7;
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

string s[1005];//same as char s[1005][1005] , 2d arr of chars , or array of strings
int dp[1005][1005]; //2d dp bcos there are two params h & w

int main() {
	clock_t begin = clock();
	shm();

	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	memset(dp, 0, sizeof (dp));
	/*
	---> Idea
		the no of ways in which a square[i][j] can be reached is
		the sum of np pf ways in which left square and above square can be reached.

	*/
	dp[0][0] = 1; //we can reach the first array in 1 way

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') { // if obstacle we cant go to that index
				dp[i][j] = 0;
				continue;
			}

			if (i > 0) dp[i][j] = dp[i][j] + dp[i - 1][j]; // value from top of that index
			dp[i][j] %= MOD;
			if (j > 0) dp[i][j] = dp[i][j] + dp[i][j - 1]; // value from left of that index
			dp[i][j] %= MOD;
		}
	}
	//picturing the dp
	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < w; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[h - 1][w - 1] << endl;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}