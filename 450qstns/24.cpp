//longest consecutive subsequence

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

int longestConsSubSeq(vector<int> &a) {
	int maxEle; // to find max elelment in input array
	// and give that as a size for freq array
	for (int j = 0; j < a.size(); j++)
		maxEle = max(maxEle, a[j]); //finding maxELement

	vector<bool> freq(maxEle + 1); //defining freq array to check if number is present or not

	for (int i = 0; i < a.size(); i++) {
		freq[a[i]] = true; //filling accordingly
	}

	int count = 0;
	int maxCount = 0;

	for (int i = 0; i < freq.size(); i++) {
		if (freq[i])
		{
			count++;
			maxCount = max(maxCount, count);
		} else
			count = 0;
	}
	return maxCount;
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = longestConsSubSeq(a);
	cout << ans << endl;
}

/*
Inp
7
2 6 1 9 4 5 3

7
1 9 3 10 4 20 2

Approach create a freq array
*/