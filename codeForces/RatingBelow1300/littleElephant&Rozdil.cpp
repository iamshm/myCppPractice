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
	long long n;
	cin >> n;
	vector<pair<long long, long long>> pii;
	long long a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		pii.push_back(make_pair(a, i));
	}
	sort(pii.begin(), pii.end());
	bool flag = true;
	if (pii[0].first == pii[1].first)
	{
		flag = false;
	}

	if (flag)
	{	cout << pii[0].second << endl;

	} else {
		cout << "Still Rozdil" << endl;
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
