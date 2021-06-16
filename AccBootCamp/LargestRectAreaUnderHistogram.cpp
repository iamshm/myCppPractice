
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
	ll n;
	cin >> n;
	vi a(n), left(n), right(n);
	for (ll i = 0 ; i < n; i++) cin >> a[i];
	stack<ll> stk;

	// Calcualte left boundaries
	for (ll i = 0; i < n; ++i)
	{
		if (stk.empty()) {
			left[i] = 0;
			stk.push(i);
		} else {
			while (!stk.empty() and (a[stk.top()] >= a[i]) ) {
				stk.pop();
			}
			left[i] = stk.empty() ? 0 : stk.top() + 1;
			stk.push(i);
		}
	}
	cerr << stk.size();
	while (!stk.empty()) stk.pop();

	for (ll i = n - 1; i >= 0; i--)
	{
		if (stk.empty()) {
			right[i] = n - 1;
			stk.push(i);
		} else {
			while (!stk.empty() and a[stk.top()] >= a[i]) {
				stk.pop();
			}
			right[i]  = stk.empty() ? 0 : stk.top() - 1;
			stk.push(i);
		}
	}
	cerr << stk.size();
	ll mArea = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll area = (right[i] - left[i] + 1) * a[i];
		mArea = max(area, mArea);
	}
	cout << mArea;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	ll t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

// 7
// 6 2 5 4 5 1 6