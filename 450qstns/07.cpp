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
	int k = 2;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - k; i < n; i++) {
		cout << a[i];
	}
	for (int i = 0; i < n - k ; i++) {
		cout << a[i];
	}
}
// 5
// 1 2 3 4 5