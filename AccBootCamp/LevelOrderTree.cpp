// Count nodes in dthe level of a tree
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

int bfsTree(int root, int n, int lvl, vector<int> adj[]) {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	vector<int> level(n + 1, -1);

	visited[root] = true;
	q.push(root);
	level[root] = 0;

	while (!q.empty()) {
		root = q.front();
		q.pop();

		for (auto it : adj[root]) {
			if (!visited[it]) {
				level[it] = level[root] + 1;
				visited[it] = true;
				q.push(it);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cerr << i << " level-> " << level[i] << endl;
		if (level[i] == lvl)
			ans++;
	}

	return ans;
}
void solve() {
	int n;
	cin >> n;
	vector<int> adj[n + 1];
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int k;
	cin >> k;

	for (auto it : adj) {
		for (auto jt : it) {
			cerr << jt << " ";
		}
		cerr << endl;
	}
	cerr << endl;
	cout << bfsTree(1, n, k, adj);

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

// 6
// 1 2
// 1 3
// 3 5
// 3 6
// 2 4
// 2
// 20
// 11 1
// 1 2
// 13 3
// 15 4
// 17 5
// 11 6
// 2 7
// 1 8
// 15 9
// 4 10
// 15 12
// 5 13
// 2 14
// 17 15
// 15 16
// 11 17
// 15 18
// 9 19
// 16 20
// 2
