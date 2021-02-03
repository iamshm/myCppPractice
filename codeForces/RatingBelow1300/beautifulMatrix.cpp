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
	int posI = 0, posJ = 0, item;
	int arr[5][5];
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> item;
			arr[i][j] = item;
			if (item == 1) {
				posI = i + 1;
				posJ = j + 1;
			}

		}
	}
	int answer = abs(posI - 3) + abs(posJ - 3);

	display(answer);
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
