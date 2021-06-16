
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
int dirctedToSink(vector<int> aSink, vector<int> adj[], int n) {
	int count = 0;
	for ( auto sink : aSink) {
		for (int i = 1; i <= n; i++) {
			auto it = std::find(adj[i].begin(), adj[i].end(), sink);
			if ( it != adj[i].end()) count++;
		}

	}
	return count;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	vector<int> bdj[n + 1];
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		bdj[y].push_back(x);
	}

	vector<int> aSink;
	vector<int> bSink;

	for (int i = 1; i < n + 1; ++i)
	{
		if (!adj[i].size()) aSink.push_back(i);
		if (!bdj[i].size()) bSink.push_back(i);
	}

	int count1 = dirctedToSink(aSink, adj, n);
	int count2 = dirctedToSink(bSink, bdj, n);
	cout << max(count2, count1);
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

// 5 6
// 1 2
// 1 3
// 1 4
// 2 5
// 3 5
// 3 5