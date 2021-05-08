// find median in row wise sorted array
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
void shm() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int binaryMedian(vector<vector<int> > a, int r, int c) {
	int maxm = a[0][0];
	int minm = a[0][c - 1];

	for (int i = 0; i < r; i++) {
		maxm = max(maxm, a[i][c - 1]);
		minm = min(minm, a[i][0]);
	}

	int desired = (r * c + 1) / 2;

	while (minm < maxm) {
		int mid = minm + (maxm - minm) / 2;
		int place = 0;

		for (int i = 0; i < r; i++) {
			place += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
		}
		if (place < desired) minm = mid + 1;
		else maxm = mid;

	}
	return minm;
}
int main()
{
	shm();
	int r, c;
	cin >> r >> c;
	vector<vector<int> > a(r, vector<int> (c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> a[i][j];

	cout << binaryMedian(a, r, c);
}

/*
Input method
3 3
1 3 5
2 6 9
3 6 9

question is to find median

Naive approach is to store the elements in a r*c size array
and then sort it and then median will be at a[r*c / 2]
tc - O(r*c(log(r*c))) (for sorting)
We can also use priority queue and find the n/2th min element


Effiient app
Binary searchmethod

https://www.youtube.com/watch?v=BpETOGNqKmo
https://www.youtube.com/watch?v=_4rxBuhyLXw
*/

