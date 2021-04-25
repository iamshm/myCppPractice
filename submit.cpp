#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

void solve() {
	int x, y;
	cin >> x >> y;
	// we can write it like
	// y = ax + b
	// where a = y/x and b = y % x
	// and no of opertn (ans) would be
	// ans += a%10 until a>0
	// lastly ans +=b;
	int ans = 0;

	int a = y / x;
	while (a > 0) {
		ans += a % 10;
		a /= 10;
	}

	cout << (ans + y % x) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}