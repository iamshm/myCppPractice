
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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a;
	set<int> in, out;
	int maxDay = 0;
	for (int i = 0; i < n; ++i)
	{

		int x, y;
		cin >> x >> y;
		int temp = max(x, y);
		maxDay = max(maxDay, temp);
		in.insert(x);
		out.insert(y);
	}

	int roomCount = 0;
	bool poss = true;
	for (int i = 1; i <= maxDay; ++i)
	{
		if (in.find(i) != in.end()) {

			roomCount++;
		}
		if (out.find(i) != out.end()) {
			roomCount--;
		}
		if (roomCount > k) {
			poss = false;
			break;
		}
	}
	if (poss) cout << "yes";
	else cout << "no";

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

// 3 2
// 1 2
// 3 6
// 5 8