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
	int num;
	int l = s.length();
	vector<int> v;
	for (int i = 0; i < l; i += 2) {
		for (int j = 0; j < l - i - 2; j += 2) {
			if (s[j] > s[j + 2]) {
				swap(s[j], s[j + 2]);
			}
		}
	}
	cout << s << endl;
}
//input -- 3+2+1
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