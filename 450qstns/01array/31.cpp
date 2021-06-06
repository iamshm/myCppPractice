//smallest subarray with sum greater than x

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
int minSubArrayX(vector<int> &a, int x) {
	int start = 0, i = 0;
	int n = a.size();
	int sumLen = n + 1;
	int sum = 0;
	while (i < a.size()) {
		while (sum <= x && i < n) sum += a[i++];

		while (sum > x && start < n) {
			sumLen = min(sumLen, i - start);
			sum -= a[start++];
		}
	}

	return sumLen;
}
int main()
{
	shm();
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << minSubArrayX(a, x);

}
/*
inp
5 9
1 10 5 2 7
inp
6 51
1 4 45 6 0 19

approach

brute force is to use two loops
outer loop will have start point and
inner will have subarray

better approach
** same idea as to find subarray with sum = x
sliding window
having a start pointer and i
adding a[i] to curr sum until it is
less or wqual to x
when it becomes more we decrement a[start]
until it is greater than x and also
we store min(sub array len)
*/