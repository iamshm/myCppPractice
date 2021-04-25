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
	int n;
	cin >> n;
	int a[n + 1][n + 1];
	memset(a, -1, sizeof(a));
	bool flag = 1;
	loop(i, 1, n) cin >> a[i][i];
	loop(i, 1, a[1][1]) {
		a[i][1] = a[1][1];
	}
	looprev(i, a[n][n], 1) {
		a[n][n - i + 1] = a[n][n];
	}
	loop(i, 2, n - 1) {
		int num = a[i][i];
		int rep = a[i][i];
		int j = i;
		while (rep > 0) {
			if (a[i][j - 1] == -1) {
				a[i][j - 1] = num;
				j--;
			} else if (a[i + 1][j] == -1) {
				a[i + 1][j] = num;
				i++;
			} else {
				flag = 0;
			}
			rep--;
		}
	}

	if (flag) {
		loop(i, 1, n) {
			loop(j, 1, n) {
				if (a[i][j] != -1)
					cout << a[i][j] << " ";
			}
			cout << endl;
		}
	} else
		cout << "-1" << endl;
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