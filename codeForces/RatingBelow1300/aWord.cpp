#include <bits/stdc++.h>
#include <cctype>
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

void lowerall(string s) {
	transform(s.begin(), s.begin() + 1, s.begin(), ::tolower);
	cout << s << endl;
}
void upperall(string s) {
	transform(s.begin(), s.begin() + 1, s.begin(), ::toupper);
	cout << s << endl;
}
void solve() {
	int upCount = 0, n;
	string s;
	cin >> s;
	n = s.length();
	upperall(s);
	// for (int i = 0; i < n; i++) {
	// 	if (isupper(s[i])) {
	// 		upCount++;
	// 	}
	// }
	// if (upCount <= (n - upCount)) {
	// 	lowerall(s);
	// } else {
	// 	upperall(s);
	// }

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
