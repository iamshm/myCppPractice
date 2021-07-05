// DFS implementation
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


char forest[1000][1000];
int n;

void visitForest(int i , int j) {
	if (i >= n || i < 0 || j >= n || j < 0 || forest[i][j] != 'T') return;

	forest[i][j] = 'W';

	visitForest(i - 1, j);
	visitForest(i, j - 1);
	visitForest(i + 1, j);
	visitForest(i, j + 1);

}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> forest[i][j];
	int noOfForest = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (forest[i][j] == 'T')
			{
				visitForest(i, j);
				noOfForest++;
			}
	cout << noOfForest;
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