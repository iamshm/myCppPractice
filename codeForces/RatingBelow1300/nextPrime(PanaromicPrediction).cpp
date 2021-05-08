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
	int a, b;
	int temp = 0;
	bool flag = true;
	cin >> a >> b;
	for (int i = a + 1; i <= b; i++) {
		for (int j = 2; j < a; j++) {
			if (i % j == 0)
			{
				flag = false;

			}
		}
		if (flag)
		{
			temp = i;
			break;

		} else {
			flag = true;
		}

	}
	if (temp == b) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}

int main()
{
	shm();
	int tc = 1;
	//cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}
