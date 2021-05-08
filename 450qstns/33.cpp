//minm swaps required to bring elements less than k together

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

int minSwap(vector<int> &a, int k) {
	int n = a.size();
	int good = 0;
	for (auto i : a)
		if (i <= k)
			good++;
	int c = 0;
	for (int i = 0; i < good; i++)
		if (a[i] > k) c++;
	int ans = c ;
	int i = 0; int j = good;
	while (j < n) {
		if (a[i] > k) c--;
		if (a[j] > k) c++;
		ans = min(c, ans);
		i++; j++;
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
	int k;
	cin >> k;
	cout << minSwap(a, k);
}

/*
inp 1
5
2 1 5 6 3
3
inp 2
3
20 12 17
6
inp3
7
2 7 9 5 8 7 4
6

idea is to make a subarray of all nos less tha k

so we find no of elements less than equal to k

and we use sliding window technique of length equal to no of elements less than k
and
find a subarray which has min no of elements greater than k

*/