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
bool searchInMatrix(vector<vector<int> > &a, int target) {
	int n = a.size();
	int m = a[0].size();
	int l = 0;
	int r = n * m - 1 ;
	int mid = (l + r) / 2;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid / m][mid % m] ==  target) return true;
		else if (a[mid / m][mid % m] < target) l = mid + 1;
		else r = mid - 1;
	}
	return false;
}
int main()
{
	shm();
	int r, c, target;
	cin >> r >> c >> target;
	vector<vector<int> > a(r, vector<int> (c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	cout << searchInMatrix(a, target);
}

/*
->linear search on n*m
tc O(n2)

->binary search on each array
tc O(nlogn)

->if it is said that the matrix is column wise and row wise sorted then
then we can start from arr[0][m-1] and if it target is smaller than current
move left else move down
until i< n and j >=0
tc O(N)

--> if it is said that it is completely sorted
	meaning if they r put in an array the arr would be already sorted
	For such case, we can use a temp arr and do binary search
	tc O(logN)
sc O(n)

***
but the optimal soltn is
assuming all of them have index
so
we can now do binary search on it as we do in linear arr

for a array of 3 * 4
index will be from 0 to 11
so for an index 7
we can access by a[i/m][j%m]
a[7/4][7%4] = a[1][3]

hence this will help us do binary search
tc O(logN)
sc O(1)
***
*/