// https://codeforces.com/contest/1509/problem/D
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
	ll n;
	cin >>  n;
	string a, b, c;
	cin >> a >> b >> c;
	ll i = 0;
	ll j = 0;
	ll k = 0;
	string ans = "";
	ll sizeOfNewString = 0;
	while (i != 2 * n and j != 2 * n and k != 2 * n) {
		char ch;
		int count0 = (int) (a[i] == '0') + (b[j] == '0') + (c[k] == '0');
		if (count0 >= 2) { // if 2 or more zeroes we will pick
			ans += '0';
			ch = '0';
		} else {// or else 1
			ans += '1';
			ch = '1';
		}
		if (a[i] == ch) i++;
		if (b[j] == ch) j++;
		if (c[k] == ch) k++;
		sizeOfNewString++;
	}
	if (i != 2 * n and 2 * n - i <= 3 * n - sizeOfNewString) ans += a.substr(i);
	else if (j != 2 * n and 2 * n - j <= 3 * n - sizeOfNewString) ans += b.substr(j);
	else if (k != 2 * n and 2 * n - k <= 3 * n - sizeOfNewString) ans += c.substr(k);
	cout << ans << endl;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	ll t = 1;
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