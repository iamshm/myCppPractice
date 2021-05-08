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
	vector<int> a;
	int c = 0;
	int totalSum = 0;
	for (int i = 0; i < 12; i++) {
		int inp;
		cin >> inp;
		totalSum += inp;
		a.push_back(inp);
	}
	sort(a.begin(), a.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += a[i];
		c++;
		if (sum >= n)
		{
			break;
		}
	}
	if (n == 0)
	{
		cout << 0 << endl;
	} else if (totalSum < n)
	{
		cout << -1 << endl;
	}
	else {
		display(c);

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
