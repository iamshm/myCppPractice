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
	long long n = 0;
	int rem;
	cin >> n;

	int temp = 0;

	while (n > 0) {
		rem = n % 10;
		n = n / 10;
		if (rem == 4 || rem == 7)
		{
			temp++;
		}
	}

	if (temp == 4 || temp == 7) {
		cout << "YES" << endl;
	}
	else {
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
