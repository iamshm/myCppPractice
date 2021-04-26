// Word break
// // https://practice.geeksforgeeks.org/problems/word-break1352/1

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

bool wordBreak(vector<string> &dict, string line) {
	unordered_set<string> dictMap;
	for (auto &word : dict) {
		dictMap.insert(word);
	}

	int n = line.size();
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) { // traversing from behind
		string substring;
		for (int j = i; j < n; j++) {
			substring.push_back(line[j]);//making a temporary substring
			// checking if that substring is available in index
			// and if the (i+1)th to n string is possible
			// as dp[i] stores it
			if (dictMap.find(substring) != dictMap.end() and dp[j + 1] == 1) {
				dp[i] = 1;
			}
		}
	}
	// cout << dp[3];
	return dp[0];
}
void solve() {
	int n;
	cin >> n;
	vector<string> dict;
	loop(i, 0, n - 1) {
		string s;
		cin >> s;
		dict.push_back(s);
	}
	string line ;
	cin >> line;
	cout <<	wordBreak(dict, line);
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

/*
we traverse from 1 to n
	for every i
		we make every possible substring and
		if its that substring is present we make the
		dp[i]  true if dp[i+1] was true
in this way we wont be soing overlapping problems
as dp will store our state
*/