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

nextPermutation(vector<int> &a) {
	int i = 0, j = 0;
	for ( i = a.size() - 2; i >= 0; i--)
		if (a[i] < a[i + 1])
			break;

	if (i < 0) reverse(a.begin(), a.end());

	else {
		for (j = a.size() - 1; j > i; j--)
			if (a[j] > a[i])
				break;
		swap(a[j], a[i]);
		reverse(a.begin() + i + 1, a.end());
	}
	return;
}
int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	nextPermutation(a);
	for (auto it : a) {
		cout << it << endl;
	}
}

/*
3
3 2 1

Approach 1
brute force :-find every possibility O(n2)

https://www.youtube.com/watch?v=LuLCLgMElus&t=493s
O(n)
follows a pattern

lets say combos with 1 2 3 4

1234
      4
    3
  2
1
1243
  4
 2 3
1
1324

  3  4
1  2

1342

  4
 3 2
1

4231

  2   1
4   3

4321
   1
  2
 3
4

4123

 1 3
4 2

so the move up n down n we have to find the beakdown

*/