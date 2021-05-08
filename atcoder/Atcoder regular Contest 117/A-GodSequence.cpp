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
	int a, b;
	cin >> a >> b;
	ll negSum = 0;
	ll posSum = 0;
	if (a < b) {
		looprev(i, -1, -b) {
			cout << i << " ";
			negSum += i;
		}
		negSum *= -1;
		loop(i, 1, a - 1) {
			cout << i << " ";
			posSum += i;
		}
		cout << (negSum - posSum) << " ";
	}
	else {
		loop(i, 1, a) {
			cout << i << " ";
			posSum += i;
		}
		looprev(i, -1, -b + 1) {
			cout << i << " ";
			negSum += i;
		}
		cout << -(negSum + posSum) << " ";

	}
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