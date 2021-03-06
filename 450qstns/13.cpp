#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int maxHere = 0, maxSoFar = 0;
	for (int i = 0; i < n; i++) {
		maxHere = maxHere + a[i] ;
		maxSoFar = max(maxHere, maxSoFar);
		maxHere = max(maxHere, 0);
	}
	cout << maxSoFar << endl;
}
/*
Kadane's ALgorithm
8
-2 -3 -4 -1 -2 1 5 -3
*/