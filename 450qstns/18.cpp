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

int getPairsCount(vector<int> &a, int k) {
	//Creating a hash map
	unordered_map<int, int> feqTable;
	for (int i = 0; i < a.size(); i++) {
		feqTable[a[i]]++;
	}
	int ans = 0 ;

	for (int i = 0; i < a.size(); i++) {
		if (2 * a[i] == k) {
			ans += max(feqTable[a[i]] - 1, 0);
			// cout << ans << endl;
		}
		/*
			lets say k= 6 and a =[3 2 1]
			here count should not get increased as there is no pair for 3
			but if we dont use this condth it will add freq of 3 i.e 1 and
			hence the ans could be wrong
		*/
		else
			ans += feqTable[k - a[i]];

	}
	return ans / 2 ;
}
int main()
{
	shm();
	int n, x ;
	cin >> n;
	vector<int> a(n);
	cin >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = getPairsCount(a, x);
	cout << ans << endl;
}

/*

4
2
1 1 1 1

4
6
1 5 7 -1
in naive solution O(n2)

Optimised soltn O(n)

we create a freq table using hashmap(using unordered map)

and we traverse the arr and check
if
reqrdSum - arr[i] gives a value which is available in hashmap

and if found we increment the ans by the freq of element
which was in hashmap
*/