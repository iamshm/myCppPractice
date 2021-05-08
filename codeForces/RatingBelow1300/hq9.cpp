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
	string str;
	cin >> str;
	int flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 33 && str[i] <= 126) {
			if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
				flag = 1;
		}
	}
	if (flag) {
		cout << "YES";
	} else {
		cout << "NO";
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
