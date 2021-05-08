// three way partitioning

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
void threeWayPartitioning(vector<int> &x, int n, int a, int b) {
	int low = 0;
	int mid = 0;
	int high = n - 1;

	while (mid <= high) {
		// for (auto &i : x ) { cout << i << " "; }
		// cout << endl;
		if (x[mid] <= a)
			swap(x[mid++], x[low++]);
		else if (x[mid] >= b )
			swap(x[mid], x[high--]);
		else
			mid++;
	}
	// cout << low << mid << high << endl;
	// cout << "final" << endl;
	for (auto &i : x ) { cout << i << " "; }
}

int main()
{
	shm();
	int n, a, b;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	cin >> a >> b;
	threeWayPartitioning(x, n, a, b);
}