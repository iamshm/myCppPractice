
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define vi vector<ll>
const int MOD = 1e9 + 7;
int n;
char s[1000][1000];
int maxSize = 0;

int findMaxForest(int i, int j ) {

	if (i >= n || i < 0 || j >= n  || j < 0 || s[i][j] != 'T') return 0;

	s[i][j] = 'W';

	return findMaxForest(i - 1, j) + findMaxForest(i, j - 1) + findMaxForest(i + 1, j) + findMaxForest(i, j + 1) + 1;

}

void solve() {
	cin >> n;
	int maxSize = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> s[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; ++j)
			if (s[i][j] == 'T') {
				maxSize = max(maxSize, findMaxForest(i, j));
			}
	cout << maxSize;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

// 5
// TTTWW
// TWWTT
// TWWTT
// TWTTT
// WWTTT