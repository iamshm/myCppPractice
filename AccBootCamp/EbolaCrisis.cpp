// Ebola Crisis

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
int grid[10005][10005];

vector<int> infected(6, 0);
vector<int> highrisk(6, 0);

int crisis(int i, int j) {
	int c = 0;
	if (i > 0 && j > 0 && grid[i - 1][j - 1] == 1) {c++; grid[i - 1][j - 1] = 0;}
	if (i > 0 && grid[i - 1][j] == 1) {c++; grid[i - 1][j] = 0;}
	if (i > 0 && j < n - 1 && grid[i - 1][j + 1] == 1) {c++; grid[i - 1][j + 1] = 0;}
	if (j > 0 && grid[i][j - 1] == 1) {c++; grid[i][j - 1] = 0;}
	if (j < n - 1 && grid[i][j + 1] == 1) {c++; grid[i][j + 1] = 0;}
	if (i < n - 1 && j < n - 1 && grid[i + 1][j + 1] == 1) {c++; grid[i + 1][j + 1] = 0;}
	if (i < n - 1 && grid[i + 1][j] == 1) {c++; grid[i + 1][j] = 0;}
	if (i < n - 1 && j > 0 && grid[i + 1][j - 1] == 1) {c++; grid[i + 1][j - 1] = 0;}
	return c;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];

		}
	}

	//visit every grid
	for (int k = 5; k >= 2; k--) {
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (grid[i][j] == k ) {
						infected[k]++;
						highrisk[k] += crisis(i, j);
					}
				}
			}
		}
	}
	for (int i = 2; i < 6; ++i)
	{
		cout << infected[i] << " ";
	}
	cout << endl;
	for (int i = 2; i < 6; ++i)
	{
		cout << highrisk[i] << " ";
	}
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
// 0 0 0 1 5
// 1 1 1 1 1
// 3 1 2 1 0
// 1 1 1 1 1
// 4 4 1 3 1
