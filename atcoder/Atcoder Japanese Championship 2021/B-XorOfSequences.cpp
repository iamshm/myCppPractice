// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_b
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
	int n, m;
	cin >> n >> m;
	vi a(n); vi b(m);
	loop(i, 0, n - 1) cin >> a[i];
	loop(i, 0, m - 1) cin >> b[i];
	int i = 0; int j = 0;
	while (i < n and j < m) {
		if (a[i] > b[j]) {
			cout << b[j] << " ";
			j++;
		} else if (a[i] < b[j]) {
			cout << a[i] << " ";
			i++;
		} else {
			i++;
			j++;
		}
	}
	while (i < n) cout << a[i++] << " ";
	while (j < m) cout << b[j++] << " ";

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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