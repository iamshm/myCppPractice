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
/*
void swap(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}
*/
void merge(int a[], int n, int b[], int m) {
	int gap = ceil((float)(n + m) / 2);
	int i = 0;

	while (gap > 0) {
		if (i + gap > m + n) //checking if the 2nd iterator (i+ gap) is out of bound if yes it means we have to
			//recompute i and gap for next iteration
		{
			// cout<< gap <<endl;
			i = 0;
			if (gap == 1)break; //checking if gap is 1 and all elements have been traversed
			gap = ceil((float)gap / 2);
		}
		else if (i < n && i + gap >= n) // when 1st iterator i is on 1st array and 2nd iterator(i+gap) on 2nd array
		{

			if (a[i] > b[i + gap - n])
				// {cout << a[i] <<" "<< b[i+gap-n]<<endl;
				swap(a[i], b[i + gap - n]);
			// cout << a[i] <<" "<< b[i+gap-n]<<endl;}
			i++;
		}
		else if (i >= n && i + gap < m + n) // when 1st iterator (i) and 2nd iterator (i+gap) both on 2nd array
		{

			if (b[i - n] > b[i + gap - n])
				// {cout << b[i-n] <<" "<< b[i+gap-n]<<endl;
				swap(b[i - n], b[i + gap - n]);
			// cout <<b[i-n] <<" "<< b[i+gap-n]<<endl;}
			i++;
		}
		else //when both iterator on 1st array
		{

			if (a[i] > a[i + gap])
				// {cout << a[i] <<" "<< a[i+gap]<<endl;
				swap(a[i], a[i + gap]);
			// cout << a[i] <<" "<< a[i+gap]<<endl;}
			i++;
		}

	}

	for (int i = 0; i < n; i++) cout << a[i];
	cout << endl;
	for (int i = 0; i < m; i++) cout << b[i];
}

int main()
{
	shm();
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m);

}

/*
input
4 5
1 3 5 7
0 2 6 8 9

Algo

=>1st approach
	take a temp a array of size n+m
	fill each element of both array to the new array and sort the new arrat
	then fill starting n element in 1st arr and the last m to the 2nd array
	time O(nlogn) space O(n)

=> 2nd approach
	for every element in 1st array comapre it with every element of 2nd array
	if element of 1st array > element of 2nd arr, swap them
	then sort the 2nd array
	for this algo to work both arrays should be sorted all times
	time O(n * mlogm) space O(1)

https://www.youtube.com/watch?v=hVl2b3bLzBw
=> 3rd approach
	GAP method
	calculate gap = ceil(n+m)/2
	traverse both the array together until gap is 1
		--> check if gap=1 and 2nd iterator is out of bond i.e complete traversal is done, break
		--> keep checking if 2nd iterator is out of bound
		->case 1: when iterator is out of bound
		->case 2: when 1st iterator on array1 and 2nd on array2
		->case 3: when 1st and 2nd iterator both on array2
		->case 4: when both on 1st iterator
	time O(log(n+m)* n) i.e. O(nlogn)
	space O(1)
*/