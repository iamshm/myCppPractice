// Search in sorted Array
// Modified Binary Search
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define vi vector<ll>
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------*/
// in a rotated sorted array
// there will be a pattern
// the numbers will incresase till highest val and
// then decrease to min val and again inc
// there will be a subarray forsure
// in which the numbers are strictly inc
// so acc to that we need to set low and high

void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int l = 0, h = n - 1, res = -1;
	while (l <= h) {
		int mid  = (l + h) / 2;
		if (a[mid] == x) {res = mid; break;}
		else if (a[mid] >= a[l]) {
			if (x >= a[l] and x <= a[mid])
				h = mid - 1;
			else
				l = mid + 1;
		} else {
			if (x >= a[mid] and x <= a[h])
				l = mid + 1;
			else
				h = mid - 1;
		}
	}
	cout << res;
}
// 7 2
// 4 5 6 7 0 1 2
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
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

