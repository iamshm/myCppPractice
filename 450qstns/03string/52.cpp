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
	string a, b, result;
	cin >> a >> b >> result;
	if (a.size() + b.size() != result.size()) {cout << "NO\n"; return;}
	int i = 0; int j = 0; int k = 0;
	while (k != result.size()) {
		if (i < a.size() && a[i] == result[k]) i++;
		else if (j < b.size() && b[j] == result[k]) j++;
		else {cout << "NO\n"; return;}
		k++;
	}
	if (i < a.size() || j < b.size()) {cout << "NO\n"; return;}

	cout << "YES\n";
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
/*
12
XY
1XY2
*/