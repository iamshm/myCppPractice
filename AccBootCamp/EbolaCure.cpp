// Ebola Cure
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


int N;
int grid[10005][10005];
int maxM = 0;
vector<int> ans(6, 0);

void findAntidote(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] == 0) return;

	maxM = max(maxM, grid[i][j]); // max antidote
	// cout << maxM << endl;
	grid[i][j] = 0; // so it doesnt get revisited

	findAntidote(i - 1, j - 1);
	findAntidote(i - 1, j);
	findAntidote(i - 1, j + 1);
	findAntidote(i, j + 1);
	findAntidote(i + 1, j + 1);
	findAntidote(i + 1, j - 1);
	findAntidote(i + 1, j);
	findAntidote(i, j - 1);

}
void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> grid[i][j];

		}
	}

	//visit every grid
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j]) {
				maxM = 0;
				findAntidote(i, j);
				ans[maxM]++;
				// cout << maxM << endl;
			}
		}
	}

	for (int i = 2; i < 6; ++i)
	{
		cout << ans[i] << " ";
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
// 1 1 0 1 1
// 3 1 0 0 0
// 1 1 0 1 1
// 4 4 0 3 1