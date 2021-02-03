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
display


void solve() {
	int temp, n;
	cin >> n;
	if (n % 2 == 1)
	{
		cout << -1 << endl;
	} else {
		cout << "2 1";
		for (int i = 3; i < n; i += 2) {
			cout << " "  << i + 1 << " " << i;
		}
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
