// all permutations of given string
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

void permute(string a, int l, int r)
{
	if (l == r) {
		cout << a << endl;
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]); // for making combinations
		permute(a, l + 1, r);
		swap(a[l], a[i]); // for backtracking,
		// this swap canscels out the above swap
		//see tutorial in last line
	}
}

// Driver Code
int main()
{
	string str = "ABCD";
	int n = str.size();
	permute(str, 0, n - 1);
	return 0;
}
/*
best explalantion
https://www.youtube.com/watch?v=GuTPwotSdYw
*/