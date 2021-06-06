// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// Rabin Karp Pattern Matching

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
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

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

#define d 256

void rabinKarp(string pat, string txt , int q) {
	int m = pat.size();
	int n = txt.size();

	int patHash = 0;
	int txtHash = 0;
	int h = 1; // to simmplify callc of rolling hash
	loop(i, 0, m - 2) {
		h = (h * d) % q;
	}
	loop(i, 0, m - 1) {
		patHash = (d * patHash + pat[i]) % q;
		txtHash = (d * txtHash + txt[i]) % q;
	}
	int j;
	loop(i, 0, n - m) {
		debug(txtHash); debug(patHash);
		if (patHash == txtHash) {
			for (j = 0; j < m; j++) {
				if (pat[j] != txt[i + j]) break;
			}
			if (j == m) cout << i << endl;
		}
		if (i < n - m) {
			txtHash = (d * (txtHash - txt[i] * h) + txt[i + m]) % q;
			if (txtHash < 0)
				txtHash = txtHash + q;
		}
	}

}

void solve() {
	int q = 101;
	string txt, pat;
	// cin >> pat;
	// getline(cin, txt);
	txt = "THIS IS A TEST TEXT TEST ING TEST";
	pat = "TEST";


	rabinKarp(pat, txt, q);
}

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
