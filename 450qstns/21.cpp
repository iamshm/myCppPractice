// subarray with sum 0
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

bool subArraySum(vector<int> &a, int reqrdSum) {
	unordered_map<int, int> hashmap;
	//hashmap[currSum] = i (index);
	int currSum = 0;
	for (int i = 0; i < a.size(); i++) {
		currSum += a[i];
		if (currSum == reqrdSum) return true ;
		if (hashmap.find(currSum - reqrdSum) != hashmap.end()) return true;
		// sum found in hashmap[currSum-reqrdSum]+1 to i
		hashmap[currSum] = i;
	}
	return false;
}
int main()
{
	shm();
	int reqrdSum = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (subArraySum(a, reqrdSum))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}


/*
Input
5
4 2 -3 1 6
5
4 2 0 1 6
for subarray sums in general

--> if there are no negative numbers we can use sliding window
using 2 iterators(start and i)
adding every element to currSum and checking if currSum > reqrdSum
if true then we increment the start pointer and
decrement a[start] from currSum and check if we get reqrdSum,
we stop this decremention until start < i -1

--> if there are negative numbers
we use hashmap to store prefix sum


hashmap -- currSum -> index
for a = [4 2 -3 1 6]
hashmap of prefix sum
		-- 4->0
		   6->1
		   3->2
		   4->3
		   10->4
we traverse and check
if we found sum
else if the currsum -reqrd sum is in hashmap
		if we found then hashmap[currsum -reqrdSum] + 1  to i is ans
or we add the Currsum to the hashmap


*/