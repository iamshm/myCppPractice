// Max sum such that no two elements are adjcacent in the subsequence

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


// greedy and dp
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int incl = a[0], excl = 0;
	for (int i = 1; i < n; ++i)
	{
		int prevIncl = incl;
		incl = excl + a[i];
		excl = max(prevIncl, excl);
	}
	cout << max(incl, excl);
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
// 4
// 3 2 7 10
// 5
// 3 2 5 10 7