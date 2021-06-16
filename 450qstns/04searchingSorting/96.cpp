// Find repeating and missing
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

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
	vi a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	// 1 . sort, if element is not at its index we founf repeating and missing
	// 2 .  USe freq array

	// 3 . Use absolute
	// repeating

	int repeating = 0, missing = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[abs(a[i]) - 1] > 0)
			a[abs(a[i]) - 1] = -1 * a[abs(a[i]) - 1];
		else
			repeating = abs(a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0 )
			missing = i + 1;
	}
	cout << repeating << " " << missing;
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

