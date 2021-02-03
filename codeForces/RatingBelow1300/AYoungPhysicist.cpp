#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1e18

#define endl "\n"
#define dis(x) cout<<#x<<"="<<x<<'\n'//"\n" is faster than endl"
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve() {
	int n;
	cin >> n;
	int temp = n;
	int sumX = 0;
	int sumY = 0;
	int sumZ = 0;
	while (temp != 0) {
		int a, b, c;
		cin >> a >> b >> c;
		sumX = sumX + a;
		sumY = sumY + b;
		sumZ = sumZ + c;
		temp--;
	}

	if (sumX == 0 && sumY == 0 && sumZ == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
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
