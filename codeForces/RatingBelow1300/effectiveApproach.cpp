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
	int n, a, in[100001];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		in[a] = i;
	}
	int m, b;
	long long Vasya = 0, Petya = 0;
	cin >> m;
	while (m--) {
		cin >> b;
		Vasya += in[b];
		Petya += n + 1 - in[b];


	}
	cout << Vasya << " " << Petya << endl;
}
/*
3
3 1 2
3
1 2 3

*/

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
