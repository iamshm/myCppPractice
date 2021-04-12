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

int merge(int arr[], int temp[], int left, int mid, int right) {
	int i, j, k;
	int inverseCount = 0;

	i = left;
	j = mid;
	k = left;

	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			inverseCount = inverseCount + (mid - 1);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	for (int i = left; i < right; i++) arr[i] = temp[i];

	return inverseCount;
}
int countInversions(int a[], int temp[], int left, int right) {

	int mid, inverseCount = 0;
	if (right > left) {
		mid = (right + left) / 2;

		inverseCount += countInversions(a, temp, left, mid - 1);
		inverseCount += countInversions(a, temp, mid, right):

			                inverseCount += merge(a, temp , left, mid + 1 , right);
		}
		return inverseCount;
	}


	int main()
{
	// shm();
	int n;
	cin >> n;
	int a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int temp[n];
	int ans = countInversions(a, temp, 0, a.size() - 1);
	cout << ans << endl;
}

/*
Approach 1 Brute force O(n2)

Approach 2
*/