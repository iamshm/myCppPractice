// creating unordered map for 1st array and
// traversing through 2nd array n
// checking if its present in map

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

string subsetArray(vector<int> &a, vector<int> &b, int n, int m) {
	unordered_map<int, int> hashTable;
	for (int i = 0; i < n; i++)
		hashTable[a[i]]++;

	bool ans = false ;

	for (int i = 0; i < m; i++) {
		if (hashTable[b[i]])
			ans = true ;
		else
			return "No";
	}
	return "Yes";
}
int main()
{
	shm();

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];

	cout << subsetArray(a, b, n, m);
}

/*
input
6
11 1 13 21 3 7
4
11 3 7 1

input
6
1 2 3 4 5 6
4
2 3 11 8
*/