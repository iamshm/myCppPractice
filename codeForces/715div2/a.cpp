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
	vi a(n, 0);
	int evenCount = 0; int oddCount = 0;
	loop(i, 0, n - 1) {cin >> a[i]; if (a[i] % 2 == 0)evenCount++; else oddCount++;}

	ll evenArray[evenCount]; ll oddArray[oddCount]; int e = 0; int o = 0;
	loop(i, 0, n - 1) {
		if (a[i] % 2 == 0) evenArray[e++] = a[i];
		else oddArray[o++] = a[i];
	}
	if (oddCount >= evenCount) {
		loop(i, 0, oddCount - 1) cout << oddArray[i] << " ";;
		looprev(i, evenCount - 1, 0) cout << evenArray[i] << " ";;
	} else {
		loop(i, 0, evenCount - 1) cout << evenArray[i] << " ";;
		looprev(i, oddCount - 1, 0) cout << oddArray[i] << " ";;
	}



	// loop(i, 0, n - 1) cout << a[i] << " ";
	cout << endl;
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