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

int palinOrNot(vector<int> &a) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int temp = a[i];
		int palin = 0;
		while (temp > 0) {
			palin = palin * 10 + temp % 10;
			temp = temp / 10;
		}
		// cout << palin << endl;
		if (a[i] != palin) return 0;
	}
	return 1;
}
void easy() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << palinOrNot(a) << endl;
	}
}

void realProblem() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int i = 0;
	int j = n - 1;
	int ans = 0 ;
	while (i < j) {
		if (a[i] == a[j])
		{
			i++; j--;
		} else if (a[i] < a[j])
		{
			i++;
			a[i] += a[i - 1];
			ans++;
		} else {
			j--;
			a[j] += a[j + 1];
			ans++;
		}
	}
	cout << ans;
}
int main()
{
	shm();
	// easy();
	realProblem();
}

/*
correct problem link
https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

2 pointer approach
5
1 4 5 9 1
*/