// Majority element
// element present more than n/2


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
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int count  = 0, element = 0;

	for (int i = 0; i < n; ++i)
	{
		if (count == 0) {
			count++;
			element = a[i];
		} else if (a[i] == element)
			count++;
		else
			count--;
	}
	// if it was said that majority element exists for sure
	// we need not do the below part
	// but as it is not said in the given qstn
	// we have to check if it is present more than n/2 times
	int countMaxFound  = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == element) countMaxFound++;
	}
	if (countMaxFound > n / 2)
		cout << element << endl;
	else cout << "No Majoruity Element" << endl;

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

// 5
// 3 1 3 2 2

// 5
// 3 1 3 3 2