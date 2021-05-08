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
	string s, s2;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)

	{
		if (s[i] == '.') {
			s2 += '0';
		}
		if (s[i] == '-' && s[i + 1] == '.') {
			s2 += '1';
			++i;

		}
		if (s[i] == '-' && s[i + 1] == '-') {
			s2 += '2';
			++i;
		}

	}
	cout << s2;

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
