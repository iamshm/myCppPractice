// move all negative nos to one sode of array
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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i] ;
	int j = 0;
	for (int i = 0; i < n; i++) { //traverse through every element
		if (a[i] < 0) // find negative numbers
		{
			if (i != j) // avoid 1st element
				swap(a[i], a[j]);
			j++;// tracks where the last negative number is
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}

//input
//9
// -12 11 -13 -5 6 -7 5 -3 -6