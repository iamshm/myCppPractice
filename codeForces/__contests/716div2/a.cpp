#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

set<int> sq;
void solve() {
	int n;
	cin >> n;
	bool found = 0;
	// for(auto &x : sq) cout << x << endl;
	loop(i, 0, n - 1) {
		int x;
		cin >> x;
		if (!sq.count(x))
		{
			found = 1;
		}
	}
	if (found) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	cin >> t;
	loop(i, 1, 200) {
		sq.insert(i * i);
	}
	while (t--) {
		solve() ;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}