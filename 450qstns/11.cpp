
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

int findDuplicates(int a[],int n){
	int slow=a[0];
	int fast=a[0];

	while(1){
		slow=a[slow];
		fast=a[a[fast]];

		if(slow== fast) break;
	}
	slow = a[0];
	while(slow!=fast){
		slow=a[slow];
		fast=a[fast];
	}
	return slow;
}
int main()
{
	shm();
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << findDuplicates(a,n);
}

/*
floyd hare and tortoise cycle detection algorithm

https://www.youtube.com/watch?v=32Ll35mhWg0&t=0s

3 
1 1 2
*/