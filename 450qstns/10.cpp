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
int minJumps (int a[], int n) {
	int maxReachPoint = a[0];
	int jumps = 1;
	int steps = a[0];
	if (n == 1) return 0 ;
	else if (a[0] == 0) return -1;
	else {
		for (int i = 1; i < n; i++) {
			if (i == n - 1) return jumps;
			maxReachPoint = max(maxReachPoint, i + a[i]);
			steps--;
			if (steps == 0) {
				jumps++;
				if (i >= maxReachPoint) return -1;
				steps = maxReachPoint - i;
			}
		}
	}
}
int main()
{
	shm();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {cin >> a[i];}
	cout << minJumps(a, n) << endl;
}
/*
// input
11
1 3 5 8 9 2 6 7 6 8 9

input
6
1 4 3 2 6 7
*/


/*
https://www.youtube.com/watch?v=5Du2iSRrbEw&t=4s
Algo
for i < n --> for each element
maxReachPoint = max(maxReachpoint, i+a[i]) --> finding maxm
steps--  --> Reducing the steps as we traverse
if steps == 0 --> this means we have jumped as we used all steps
	jumps++ --> increment jumpsas we jumped
	steps = maxReachPoint - i  -->now calculate steps depending on max ReachPoint
*/