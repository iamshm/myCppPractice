// buy sell stocks twice

/*
buy sell stock once is basically max difference

buy sell twice follows same idea
*/

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
int maxProfitSimpleMethod(vector<int> &a) {
	int n = a.size();
	vector<int> profit(n);

	// right to left traversal
	int maxPrice = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > maxPrice)
			maxPrice = a[i];
		profit[i] = max(profit[i + 1], maxPrice - a[i]);
	}
	int minPrice = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < minPrice)
			minPrice = a[i];
		profit[i] = max(profit[i - 1], profit[i] + a[i] - minPrice);
	}
	return profit[n - 1];

}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << maxProfitSimpleMethod(a);
}
/*
input
7
2 30 15 10 8 25 80
*/