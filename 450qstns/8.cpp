// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

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
	int a[n];
	for (int i = 0; i < n; i++) {cin >> a[i];}
	int maxSofar = 0, maxHere = 0;
	for (int i = 0; i < n; i++) {
		maxHere = maxHere + a[i];
		if (maxHere < 0)
		{
			maxHere = 0;
		} else if (maxSofar < maxHere)
		{
			maxSofar = maxHere;
		}
	}
	cout << maxSofar << endl;
}