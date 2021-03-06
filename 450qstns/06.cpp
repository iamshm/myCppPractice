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

void findUnion(int a1[], int a2[], int m, int n) {
	if (m > n)
	{
		int *temparr = a1;
		a2 = a1;
		a1 = temparr;

		int temp = m;
		m = n;
		n = temp;
	}
	sort(a1, a1 + m);

	for (int i = 0; i < m; i++) {
		cout << a1[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		if (!binary_search(a1, a1 + m, a2[i]))
			cout << a2[i] << endl;
	}
}
void findIntersection(int a1[], int a2[], int m , int n) {
	if (m > n) {
		int *temparr = a1;
		a2 = a1;
		a1 = temparr;

		int temp = m;
		m = n;
		n = temp;
	}
	sort(a1, a1 + m);
	for (int i = 0; i < n; i++) {
		if (binary_search(a1, a1 + m, a2[i]))
		{
			cout << a2[i] << endl;
		}
	}
}
int main()
{
	shm();
	int n, m;
	cin >> m >> n;
	int a[n], b[m];
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	//union
	findUnion(a, b, m, n);
	cout << "Intersection" << "\n";
	findIntersection(a, b, m, n);
}

// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3