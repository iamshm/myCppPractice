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

void rotateRight(vector<int> &a , int outOfPlaceIndex, int to) {
	int n = a.size();
	int temp = a[to]; // storing the last element
	for (int i = to; i > outOfPlaceIndex; i--) { // rotating right
		a[i] = a[i - 1]; // storing the found element in the outofplaceIndex
	}
	a[outOfPlaceIndex] = temp;
}
void rearrange(vector<int> &a) {
	int outOfPlaceIndex = -1 ;
	for (int i = 0; i < a.size(); i++) {
		if (outOfPlaceIndex >= 0 ) // if we found an item out of its place
		{
			if ( (a[outOfPlaceIndex] >= 0 && a[i] < 0)
			        || (a[outOfPlaceIndex] < 0 && a[i] >= 0)) // we search for a replacement
			{
				rotateRight(a, outOfPlaceIndex, i);//place the replacement in the out of placeIndex and rotate that subarray to right
				if (i - outOfPlaceIndex >= 2)
					outOfPlaceIndex += 2; //updating outOFPlaceIndex
				else
					outOfPlaceIndex = -1;

			}

		}
		if (outOfPlaceIndex == -1) // we search for outofPlace index
			if (((a[i] >= 0) && (i % 2 == 0)) || ((a[i] < 0) && (i % 2 == 1)))
				outOfPlaceIndex = i ;

	}
}

int main()
{
	shm();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	rearrange(a);
	for (auto i : a ) { cout << i << " "; }
}


/*

https://www.youtube.com/watch?v=5MeI5Kk8KTQ

We traverse the array and search if there is any outOfPLace element
and then find a replacement for it.

outOfPlace --> if negative ele in odd index or positive ele in even index
Replacememnt --> for negative outOFPlace we search positive number and for positive outOfPlace
				 we search negative number

while finding replacement if we move 2 index more than the outOfPlaceIndex, first we
implement the correction and
 then we update the outOfPlaceIndex.(line 33)


*/