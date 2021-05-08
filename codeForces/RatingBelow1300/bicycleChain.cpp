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
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	int b[m];
	for (int i = 0; i < m; i++) cin >> b[i];
	int maxm = 0, count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[j] % a[i] == 0)
			{
				int candidate = b[j] / a[i];

				if (candidate > maxm)
				{
					maxm = candidate;
					count = 1;
				} else if (candidate == maxm)
				{
					count++;
				}

			}
		}
	}
	display(count);

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
