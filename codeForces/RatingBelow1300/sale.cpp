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
	cin >> n >> m;
	vector<int> a;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);

	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] < 0)
		{
			sum += abs(a[i]);
		} else {
			break;
		}

	}
	display(sum);
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
