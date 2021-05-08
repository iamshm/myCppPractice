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
	int m, n;
	cin >> n >> m;
	int a[n] , maxindex = -1, double qt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m && qt <= ceil((double)a[i] / m))//ceil will increase the value to next int
		{
			qt = ceil((double)a[i] / m);

			maxindex = i + 1;
		}
	}
	if (maxindex == -1)
	{
		cout << n << endl;
	} else {
		cout << maxindex << endl;
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
