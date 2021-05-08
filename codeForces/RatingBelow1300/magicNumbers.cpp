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
	string s;
	cin >> s;

	int n = s.length();
	bool flag = true;
	int i = 0;
	while (i < n) {
		if (s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4')
		{
			i = i + 3;
			continue;
		} else if (s[i] == '1' && s[i + 1] == '4')
		{
			i = i + 2;
			continue;
		} else if (s[i] == '1') {
			i++;
			continue;
		} else {
			flag = false;
			break;
		}
	}
	if (flag)
	{
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
