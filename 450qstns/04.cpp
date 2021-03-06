// sort without sorting algo 0,1,2
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

void simpleSolution (int *a, int n) {
	int count0 = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
		{
			count0++;
		} else if (a[i] == 1)
		{
			count1++;
		} else {
			count2++;
		}
	}
	for (int i = 0; i < count0; i++) {
		a[i] = 0;
	}
	for (int i = count0; i < count0 + count1; i++) {
		a[i] = 1;
	}
	for (int i = count0 + count1; i < n; i++) {
		a[i] = 2;
	}
	return;
}
void printans(int *arr, int n) {
	for (int i = 0; i < n; i++) cout << arr[i];
}
int main()
{
	shm();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	simpleSolution(a, n);
	// dutchFlagAlgo(a, n);
	printans(a, n);
}