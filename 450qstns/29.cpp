// Trapping Rain water

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
int trappingWater(vector<int> &a) {
	int n = a.size();
	int l = 0;
	int r = n - 1;
	int leftmax = a[0];
	int rightmax = a[n - 1];
	int ans = 0;
	while (l < r) {
		if (a[l] <= a[r])
		{
			if (a[l] >= leftmax) leftmax = a[l];
			else ans += leftmax - a[l];
			l++;
		} else {
			if (a[r] >= rightmax) rightmax = a[r];
			else ans += rightmax + a[r];
			r--;
		}

	}
	return ans;
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << trappingWater(a) << endl;

}

/*
-->brute force
for every element find its leftmax n right max
O(n2)

-->better
traverse the array once left to right and
this will give left max at every point
traverse the array again from right to left
and this will give rightmax

now we leftmax and right max for every index so
we can find the volume of wate trapped at every index
tc -- O(n)
sc -- O(n)

--> Optimal
https://www.youtube.com/watch?v=m18Hntz4go8&t=1195s
if a[l]<= a[r]
	if a[l]>leftmax => leftmax =a[i]
	else ans+=leftmax-a[l]
else
	if a[r] > rightmax => rightmax = a[i]
	else ans += rightmax-a[r]
tc -- O(n)
sc --O(1)
*/