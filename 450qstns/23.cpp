// max product sub array
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
long long int maxProductSubarray(vector<int> &a) {
	int  maxVal = 1;
	int minVal = 1;
	int maxProduct = 0 ;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < 0) swap(minVal, maxVal);
		minVal = min(a[i], a[i] * minVal);
		maxVal = max(a[i], a[i] * maxVal);
		maxProduct = max(maxProduct, maxVal);
	}
	return maxProduct;
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long int ans = maxProductSubarray(a);
	cout << ans;
}


/*
inp
5
6 -3 -10 0 2

*/