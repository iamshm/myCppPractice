
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

void solve() {
	int n;
	cin >> n;
	vector < vector<int> > a(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	// add column height
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] != 0 and i != 0)
				a[i][j] += a[i - 1][j];
		}
	}
	//sort every row
	for (int i = 0; i < n; ++i)
	{
		sort(a[i].begin(), a[i].end());
	}
	//area calc
	int mArea = 0, area = 0;
	for (int i = 0; i < n; ++i)
	{	int width = 1;
		for (int j = n - 1; j >= 0 ; j--)
		{
			area = a[i][j] * width;
			width++;
			mArea = max(area, mArea);
		}
	}
	cout << mArea << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

// 1
// 4
// 1 0 0 1
// 1 1 0 1
// 1 1 0 1
// 1 1 0 1