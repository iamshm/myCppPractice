//chocolate distribution problem

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

long long findMinDiff(vector<long long> &a, int m) {
	sort(a.begin(), a.end());
	long long minm = a[m - 1] - a[0];
	for (long long i = 0; i < m; i++)
		minm = min(minm, a[m + i - 1] - a[i]);
	return minm	;
}
int main()
{
	shm();
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long ans = findMinDiff(a, m);
	cout << ans;
}

/*
Approach

we need minm difference
so sorting will help us get it
then we can tarverse the loop to find which
set(i to m) of packets will give minm
*/