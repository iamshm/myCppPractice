// all possible subsequences
// https://www.geeksforgeeks.org/print-subsequences-string/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)


void printSubsequence(string input, string output) {
	if (input.empty())	{
		cout << output << ", ";
		return;
	}
	// for every letter there two options
	// it can be in the sebsequence
	// or it cant be.
	// so there are 2^n subsequences
	printSubsequence(input.substr(1), output + input[0]);
	printSubsequence(input.substr(1), output);
}
void solve() {
	string s;
	cin >> s;

	string output = "";
	printSubsequence(s, output);
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