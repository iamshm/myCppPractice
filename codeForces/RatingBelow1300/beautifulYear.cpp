#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define debug(x) cout<<#x<<"="<<x<<'\n'//"\n" is faster than endl"
#define display(x) cout<<x<<'\n'//"\n" is faster than endl"
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


void solve() {
	int y;
	cin >> y;
	while (true)
	{
		y += 1;
		int a = y / 1000;
		int b = y / 100 % 10;
		int c = y / 10 % 10;
		int d = y % 10;
		if (a != b && a != c && a != d && b != c && b != d && c != d)
		{
			break;
		}
	}
	display(y);
}

int main()
{
	shm();
	int tc = 1;
	// cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}

