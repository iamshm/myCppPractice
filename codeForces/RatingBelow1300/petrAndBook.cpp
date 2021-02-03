#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define debug(x) cout<<#x<<"="<<x<<'\n' //"\n" is faster than endl"
#define display(x) cout<<x<<'\n'
#define precision(x,y)  cout<<fixed<<setprecision(y)<<x<<endl
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
void solve() {
	int pageleft = 0, n;
	cin >> n;
	int a[8];
	for (int i = 1; i <= 7; i++) {
		cin >> a[i];
	}
	int i = 1;
	while (n > 0) {
		if (n > a[i])
		{
			n -= a[i];
			i++;
			if (i == 8)
			{
				i = 1;
			}
		} else {
			break;
		}

	}
	display(i);
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
