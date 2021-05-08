// https://atcoder.jp/contests/abc199/tasks/abc199_b
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

void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	ll minm = inf;
	ll maxm = -1;
	loop(i, 0, n - 1) {
		cin >> a[i];
		maxm = max(maxm, a[i]);
	}
	loop(i, 0, n - 1) {
		cin >> b[i];
		minm = min(minm, b[i]);
	};
	if ( minm - maxm < 0) {
		cout << "0" << endl;
	} else {
		cout << minm - maxm + 1 << endl;
	}

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