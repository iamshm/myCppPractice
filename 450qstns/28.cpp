//triplet sum in array

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

bool tripletSumWithSet(vector<int> &a, int n, int sum) {
	for (int i = 0; i < n - 2; i++) {
		unordered_set<int> s;
		int curr = sum - a[i];
		for (int j = i + 1; j < n; j++) {
			if (s.find(curr - a[j]) != s.end())
				return 1;
			s.insert(a[j]);
		}
	}
	return 0;
}

bool tripletSumWithOutSet(vector<int> &a, int n, int sum) {
	sort(a.begin(), a.end());

	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			int curr = a[i] + a[l] + a[r];
			if (curr == sum)
				return 1;
			else if (curr < sum ) l++;
			else r--;
		}
	}
	return 0;
}
int main()
{
	shm();
	int n, sum;
	cin >> n >> sum;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << tripletSumWithSet(a, n, sum);
	cout << tripletSumWithOutSet(a, n, sum);
}

/*
Input;-
6 13
1 4 45 6 10 8
in set approach

we r subtracting 2 nos from reqrdSum and
looking up if the 3rd number is present in the set

in non set approach
3 pointers
i
l=i+1
r = n-1

and comparing a[i] + a[l] + a[r] with sum
if equal ans found
if less increment l
if more decrement r
until l<r
*/