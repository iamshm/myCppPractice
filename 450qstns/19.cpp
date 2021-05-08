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

vector<int> commonElements (vector<int> &a, vector<int> &b, vector<int> &c) {
	int n1 = a.size();
	int n2 = b.size();
	int n3 = c.size();
	vector<int> v;
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2 && k < n3) {
		if (a[i] == b[j] && b[j] == c[k])
		{
			v.push_back(a[i]);
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j]) i++;
		else if (b[j] < c[k]) j++;
		else k++;
		// to eliminate duplicates
		int ii = a[i - 1];
		while (a[i] == ii) i++;
		int jj = b[j - 1];
		while (b[j] == jj) j++;
		int kk = c[k - 1];
		while (c[k] == kk) k++;
	}
	if (v.size() == 0) return { -1};
	return v;
}
int main()
{
	// shm();

	int n1;
	cin >> n1;
	vector<int> a(n1);
	for (int i = 0; i < n1; i++) cin >> a[i];

	int n2;
	cin >> n2;
	vector<int> b(n2);
	for (int i = 0; i < n2; i++) cin >> b[i];

	int n3;
	cin >> n3;
	vector<int> c(n3);
	for (int i = 0; i < n3; i++) cin >> c[i];

	vector<int> ans = commonElements(a, b, c);

	for (auto i : ans ) cout << i << endl;

}

/*
Input:-
6
1 5 10 20 40 80
5
6 7 20 80 100
8
3 4 15 20 30 70 80 120

https://www.youtube.com/watch?v=ajWCEu1razQ
Approach 1:-
we can create hash map for all 3 arrays (unordered map)
And for every element in arr1 we will check if its
present in hashmap 1 hashmap2 hashmap3

unordered map insertion and look up i O(1)

Approach 2:-
it is sorted so

if a[i] = b[j] = c[k]
   ans found and i++,j++,k++
else if a[i] < b[j] i++
else if b[j] < c[k] j++
else k++

basically whichever is smallest gets incremented
*/