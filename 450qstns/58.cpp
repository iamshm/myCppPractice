// split string into substring having equlal 0 n 1
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
	string s;
	cin >> s;
	int ans = 0;
	int count0 = 0;
	int count1 = 0;
	loop(i, 0, s.size() - 1)	{
		if (s[i] == '0') count0++;
		else count1++;

		if (count1 == count0) ans++;
	}
	if (count0 != count1) cout << -1;
	else cout << ans;
}
//we count no of 0 n 1 every time their counts r
// equal means we have found a substring
// at last we check if count of 0 n 1 are equal or not
// if unequal we cant split them as asked

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