// Number of customers who dont get a computer
// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/

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

void solve() {
	int computers ;
	cin >> computers;
	string s;
	cin >> s;
	int seen[26] = {0};
	// 0 --> customer came
	// 1 --> customer not alloted to pc
	// 2 --> customer alloted to pc
	int ans = 0;
	int occupied = 0; // to track no of pc used

	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - 'A';

		if (seen[idx] == 0) { // if new cust check
			// check if pc available
			seen[idx] = 1;
			if (occupied < computers) { // if available he will use
				occupied++;
				seen[idx] = 2; // pc alloted to that cust
			} else { // if pc unavailable then he will leave
				ans++;
			}
		} else if (seen[idx] == 2) { // if cust is alloted it means
			// now cust is leaving
			occupied--; // reduce used pc count
			seen[idx] = 0;
		}
	}
	cout << ans;
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


