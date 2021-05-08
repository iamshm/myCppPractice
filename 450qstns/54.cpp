// Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

string s; int n;
int maxlength;
void dpApproach() {
	cin >> s;
	n = s.size();
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	//every letter is a substring of length 1
	maxlength = 1;
	loop(i, 0, n - 1) {
		dp[i][i] = 1;
	}
	int startOfMaxSubArray = 0;
	//preprocessing for substring of size 2
	loop(i, 0, n - 2) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			maxlength = 2;
			startOfMaxSubArray = i;
		}
	}
	// now processing dp for substring of size >2
	loop(k, 3, n) {
		//k is length of substring
		loop(i, 0, n - k) {
			int startOfThisSubArray = i;
			int endOfThisSubArray = i + (k - 1);
			if ((s[startOfThisSubArray] == s[endOfThisSubArray]) && dp[startOfThisSubArray + 1][endOfThisSubArray - 1] == 1) {
				dp[startOfThisSubArray][endOfThisSubArray] = 1;
				if (k > maxlength) {
					startOfMaxSubArray = startOfThisSubArray;
					maxlength = k;
				}
			}
		}
	}
	loop(i, startOfMaxSubArray, startOfMaxSubArray + maxlength - 1) {
		cout << s[i];
	}
	// picturing the dp
	// loop(i, 0, n - 1	) {
	// 	loop(j, 0, n - 1) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << "\n" << maxlength;
}

int ExpansionHelper(int left , int right) {
	while (left >= 0 && right < n && (s[left] == s[right]) ) {
		left--;
		right++;
	}
	return right - 1 - left;
}
void midToExtremeExpansion() {
	cin >> s;
	n = s.size();
	int start = 0; int end = 0;
	loop(i, 0, n - 1) {
		int len1 = ExpansionHelper(i, i);
		int len2 = ExpansionHelper(i, i + 1);
		int len = max(len1, len2);
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	loop(i, start, end) {
		cout << s[i];
	}
	cout << "\n" << end - start + 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	//cin >> t;
	while (t--) {
		dpApproach();
		midToExtremeExpansion();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}