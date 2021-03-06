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

void getminDiff(int a[], int n, int k) {
	vector<pair<int, int>> possibleheights;
	std::vector<int> visitedTowers(n);
	for (int i = 0; i < n; i++) {
		if (a[i] - k >= 0)
			possibleheights.push_back({a[i] - k, i});
		possibleheights.push_back({a[i] + k, i});
	}
	sort(possibleheights.begin(), possibleheights.end());

	int visitedCount = 0;
	int left = 0;
	int right = 0;

// size of every window will be determined by checking if all towers are visited (visited towers array)
//creating a temp ans by traversing first window
	//Process-->
	while (visitedCount < n && right < possibleheights.size()) {
		if (visitedTowers[possibleheights[right].second] == 0) //if tower is not visited increment the counter
			visitedCount++;
		visitedTowers[possibleheights[right].second]++;// whenever a tower is visited update the frequency in visitedtower arraay
		right++;// increment the window
	}
	int ans = possibleheights[right - 1].first - possibleheights[left].first; //ans from first window

	while (right < possibleheights.size()) {
		//will decrement the visitedCount only if the visited frequecy of the tower is 1
		//if frequency is 2 it means that tower is present in the window more than once, so we cant reduce the visitedCount
		if (visitedTowers[possibleheights[left].second] == 1)
			visitedCount--;
		visitedTowers[possibleheights[left].second]--;
		left++;//moving the left side of window

		//now we will repeat the above process
		//for every window and store the min as ans
		while (visitedCount < n && right < possibleheights.size()) {
			if (visitedTowers[possibleheights[right].second] == 0)
				visitedCount++;
			visitedTowers[possibleheights[right].second]++;
			right++;
		}
		if (visitedCount == n )
			ans = min(ans, possibleheights[right - 1].first - possibleheights[left].first);
		else
			break;
	}
	cout << ans ;
}

int main()
{
	shm();
	int k, n;
	cin >> k >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	getminDiff(a, n, k);
	return 0;

}
/*
 input 1
2 4
1 5 8 10
input 2
6 3
1 15 12
input 3
3 5
9 10 11 12 13
*/