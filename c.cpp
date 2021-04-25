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
	int  n;
	string s;
	cin >> n;
	cin >> s;
	int q;
	cin >> q;
	bool flip = 0;
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 2) {
			flip ^= 1;
		} else {
			if (!flip) {
				swap(s[a - 1], s[b - 1]);
			} else {
				if ( a > n) a -= n;
				else a += n;
				if (b > n) b -= n;
				else b += n;;
				swap(s[a - 1], s[b - 1]);
			}
		}
	}

	string s1, s2;
	loop(i, 0, n - 1) {
		s1.push_back(s[i]);
	} loop(i, n, 2 * n - 1) {
		s2.push_back(s[i]);
	}
	if (flip) {
		swap(s1, s2);
	}
	cout << s1 << s2 << endl;
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