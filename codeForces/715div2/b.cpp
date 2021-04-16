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
	int n;
	cin >> n;
	string s; cin >> s; vector<int> visited(n, 0);
	int mCount = 0;
	loop(i, 0, n - 1) {
		if (s[i] == 'M') mCount++;
	}
	if (s[0] == 'M' || s[n - 1] == 'M' || mCount != n / 3) {
		cout << "NO" << endl;
		return ;
	}
	int w = n / 3;
	cout << "YES" << endl;

	//tmt
	int i = 0;
	while (i + 2 < n) {
		if (s[i] == 'T' and s[i + 1] == 'M' and s[i + 2] == 'T') {
			visited[i] = visited[i + 1] = visited[i + 2] = 1;
		}
	}

	// tm t


	// t mt


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