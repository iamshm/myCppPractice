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
	ll n, m;
	cin >> n >> m;
	vi a[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{	int x;
			cin >> x;
			a[i].push_back(x);
		}

	}
	loop(i, 0, n - 1) {
		if (i % 2 == 0) {
			sort(a[i].begin(), a[i].end());
		} else {
			sort(a[i].rbegin(), a[i].rend());
		}
	}
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	fastio();
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