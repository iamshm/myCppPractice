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


int median(int a[], int n) {
	if (n % 2 == 0) return (a[(n - 1) / 2] + a[n / 2]) / 2;
	else return a[n / 2];
}
int getMedian(int a[], int b[], int n) {
	if (n <= 0) return -1;
	if (n == 1) return (a[0] + b[0]) / 2;
	if (n == 2 ) return (max(a[0], b[0]) + min(a[1], b[1])) / 2;

	int m1 = median(a, n);
	int m2 = median(b, n);
	if (m1 == m2) return m1;
	if (m1 < m2) {
		if (n % 2 == 0) return getMedian(a + n / 2 - 1, b, n - n / 2 + 1);
		return getMedian(a + n / 2, b, n - n / 2);
	}
	if (m1 > m2)
	{
		if (n % 2 == 0) return getMedian(b + n / 2 - 1, a, n / 2 + 1);
		return getMedian(b + n / 2, a, n - n / 2);
	}
	return 0;
}
int main()
{
	shm();
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	cout << getMedian(a, b, n);
}

/*
inp1
5
90 100 78 89 67
inp2
4
56 67 30 79

approach 1
we know the what will be the location of median in 2n size array - n-1 & n element
so we compare the elements traversing in a sorted manner and as we reach to the n-1th and nth element we print the median
tc O(n) sc O(1)

approach 2
use a temp aaray of size 2n and then sort that array
O(nlogn)
sc O(n)

approach 3
merge and sort the array without using extra space
 while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
tc O(nlogn)
sc O(1)

 ** approach 4 **
1) Calculate the medians m1 and m2 of the input arrays ar1[] and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.return m1 (or m2)
3) If m1 is greater than m2, then median is present in one of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_| ])
    b)  From m2 to last element of ar2  (ar2[ |_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[ |_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_| ])
5) Repeat the above process until size of both the subarrays  becomes 2.
6) If size of the two arrays is 2 then use below formula to get the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2

*/