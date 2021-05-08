// next Permutation in 15.cpp Explanation

// 	https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// https://www.youtube.com/watch?v=LuLCLgMElus&t=493s
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
	vector<int> a(n);
	loop(i, 0, n - 1) cin >> a[i];

	int i = 0; int j = 0;
	for (i = n - 2; i >= 0; i--) {
		if (a[i] < a[i + 1])
			break;
	}
	if (i < 0)
		reverse(a.begin(), a.end());
	else {
		for (j = n - 1; j > i; j--) {
			if (a[j] > a[i])
				break;
		}
		swap(a[i], a[j]);
	}
	reverse(a.begin() + i + 1, a.end());
	loop(k, 0, n - 1) cout << a[k];
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