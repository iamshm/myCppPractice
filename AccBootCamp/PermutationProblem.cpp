
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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
void kswapMax(vector<int> &a, int k) {
	// we can use the fact they will be first n natural nos
	int n = a.size();
	unordered_map<int, int> umap; // to store <ele,idx>
	for (int i = 0; i < n; ++i)
		umap.insert(make_pair(a[i], i));
	if (n <= k)
		sort(a.begin(), a.end(), greater<int>());
	else {
		for (int i = n; i > 0; i--)
		{
			if (k > 0) { // if swaps r available
				int idxOfCur = umap[i]; //get index of current elememnt, say X
				int bestPos = n - i; // get best poi for ele at this iteration
				if (idxOfCur != bestPos) { // if x is not at bestpos
					umap[i] = bestPos; // assign best posi to it in map
					int temp = a[bestPos]; // get the element which is at bestpos
					umap[temp] = idxOfCur; // give it the posi of X
					swap(a[bestPos], a[idxOfCur]); // swap those elements in aarray
					k--;
				}
			}
		}
	}
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	kswapMax(a, k);
	for (auto &x : a) {
		cout << x ;
	}
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
// 5 3
// 4 5 2 1 3
