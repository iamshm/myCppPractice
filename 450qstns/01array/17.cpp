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

int buySellStock(vector<int> &a) {
	int maxProfit = 0;
	int minm = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (a[i] < minm) minm = a[i];
		else if (a[i] - minm > maxProfit) maxProfit = a[i] - minm;
	}
	return maxProfit;
}

int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << buySellStock(a) << endl;
}

/*
Input:-
6
7 1 5 3 6 4

Brute Force O(n2)

while traversing through the array
we will keep track of minm and maxm element
	as their difference will be maxProfit

we can store min and for every i we can check if i- min > maxProfit
*/