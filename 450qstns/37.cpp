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

vector<int> spiralTraversal(vector<vector<int> > a, int r, int c ) {
	int top  = 0;
	int down = r - 1;
	int left = 0;
	int right = c - 1;
	int dir = 0;
	vector<int> ans;
	while (top <= down && left <= right) {
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
				ans.push_back(a[top][i]);
			top++;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= down; i++)
				ans.push_back(a[i][right]);
			right--;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
				ans.push_back(a[down][i]);
			down--;
		}
		else if (dir == 3)
		{
			for (int i = down; i >= top; i--)
				ans.push_back(a[i][left]);
			left++;
		}
		dir = (dir + 1) % 4;
	}
	return ans;
}
int main()
{
	shm();
	int r, c;
	cin >> r >> c;
	vector<vector<int> > a(r, vector<int> (c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];

	vector<int> ans(r * c);
	ans = spiralTraversal(a, r, c);
	for (auto x : ans )
		cout << x << endl;
}

/*
input

4 4
1  2  3  4
5  6  7  8
9  10  11  12
13  14  15 16

approach https://www.youtube.com/watch?v=1ZGJzvkcLsA
4 pointers to keep track
dir variable for direction
0 means left to right
1 means top to down
2 means right to left
3 means down to top
*/