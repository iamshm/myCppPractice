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

vector<vector<int>> mergeDuplicates(vector<vector<int>> &intervals) {

	vector<vector<int>> mergedIntervals ;
	if (intervals.size() == 0) return mergedIntervals;
	sort(intervals.begin(), intervals.end());
	vector<int> tempInterval = intervals[0];
	for (auto it : intervals) {
		if (it[0] <= tempInterval[1])
		{
			tempInterval[1] = max(it[1], tempInterval[1]);
		} else {
			mergedIntervals.push_back(tempInterval);
			tempInterval = it;
		}
	}
	mergedIntervals.push_back(tempInterval);
	return mergedIntervals;
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int> (2, 0)) ; // 2D array of size n * 2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) cin >> a[i][j];
	}

	vector<vector<int>> ans = mergeDuplicates(a);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < 2; j++) cout << ans[i][j] << " ";
		cout << endl;
	}
}

/*
4
1 3
2 6
8 10
15 18

Brute force approach := traverse through every input and check for overlaps

https://www.youtube.com/watch?v=2JzRBPFYbKE&t=521s
Better approach :=
-> we need to sort for this algo to work
-> maintain a temp vector of size 2 having vlue of first interval
-> now compare every interval[1] with the temp[1] (comparing with the 2nd value in the interval)
-> if overlapping update the temp[1] value accordingly
	-> else push the temp vector to a ans vector

time complexity :- sorting O(nlogn), traversal O(N)
*/