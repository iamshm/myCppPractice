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
	int n;
	cin >> n;
	vector<char> nuts(n);
	set<char> s;
	vector<char> bolts(n);
	for (int i = 0; i < n; i++) {
		cin >> nuts[i];
		s.insert(nuts[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> bolts[i];
	}
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		if (s.find(bolts[i]) != s.end()) ans.push_back(bolts[i]);
	}
	sort(ans.begin(), ans.end());
	for (auto x : ans ) { cout << x << " ";}


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
