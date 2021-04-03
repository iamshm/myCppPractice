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
	int n, m;
	cin >> n >> m;
	std::vector<vector<int> > v(n, vector<int> (n, 0));
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		v[p][q] = 1;
	}
	vector<int> people(m);
	for (int i = 0; i < m; i++) cin >> people[i];
	int cost, myFunds;
	cin >> cost >> myFunds;
	int capacity = myFunds % cost;

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
