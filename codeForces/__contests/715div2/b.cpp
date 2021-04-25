// https://codeforces.com/contest/1509/problem/B
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

bool solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	std::vector<int> t, m;
	loop(i, 0, n - 1) {
		if (s[i] == 'T') t.push_back(i);
		else m.push_back(i);
	}
	if (t.size() != 2 * m.size()) return false; // t should be twice of m

	loop(i, 0, m.size() - 1)
	if (m[i] < t[i] || m[i] > t[i + m.size()] ) return false;
	//if ith 'M' is befor ith 'T' or if it is after i+msize th 'T'
	return true;



}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	cin >> t;
	while (t--) {
		cout << (solve() ? "YES" : "NO") << endl;

	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}