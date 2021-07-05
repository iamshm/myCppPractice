// binary Seaarch
// bisection approach
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

// getting wrong
int binarySearch(int a, int b, int c, int k) {
	int x  = INT_MAX;
	if ( c >= k)	return 0;

	int right = k - c;
	int left = 0 ;
	int ans = INT_MAX;

	while (left <= right ) {
		int mid = (left + right) / 2;

		int eqn = (a * mid * mid) + (b * mid);

		if (eqn > k - c) {
			x = min(x, mid);
			right = mid - 1;
		} else if (eqn < k - c) {
			left = mid + 1;
		} else {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}
	return min(x, ans);
}

int linearSearch(int a, int b, int c, int k) {
	int j = 0;
	int eqn = (a * j * j) + (b * j) + c;
	while (eqn <= k) {
		j++;
		eqn = (a * j * j) + (b * j) + c;
	}
	return j;
}
void solve() {
	int a, b, c, k;

	cin >> a >> b >> c >> k;

	cout << binarySearch(a, b, c, k) << endl;
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
// 3
// 3 4 5 6
// 3 4 5 5
// 3 4 5 150

