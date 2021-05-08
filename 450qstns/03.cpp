//k th max min
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
	int t;
	cin >> t ;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		priority_queue<int, vector<int>, greater<int>> minH;//minHeap
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			minH.push(arr[i]); // creating minHeap
		}
		int k;
		cin >> k;
		int ans, i = 1;
		while (!minH.empty()) {
			if (i == k)
			{
				ans = minH.top();
			}
			i++;
			minH.pop(); // Deletion takes log N
		}
		cout << ans << endl ;
	}
}
// Input:
// 2
// 6
// 7 10 4 3 20 15
// 3
// 5
// 7 10 4 20 15
// 4



// there are 3 approach for this problem
// 1st Sort O(nlogN)
// 2nd MIn heap Max heap O(n+ klogN)
// 3rd Partition approach DOnt know yet