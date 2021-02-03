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
	int temp, n;
	cin >> n;
	int a, b;
	int l, r, u, d;
	vector<pair<int, int>> c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		c.push_back(make_pair(a, b));
	}
	long long points = 0;
	for (int i = 0; i < n; i++) {
		l = r = u = d = 0;
		for (int j = 0; j < n; j++) {
			if (c[i].first == c[j].first)
			{
				if (c[j].second > c[i].second)u++;
				if (c[j].second < c[i].second)d++;
			}
			if (c[i].second == c[j].second)
			{
				if (c[j].first > c[i].first)l++;
				if (c[j].first < c[i].first)r++;
			}
		}
		if (l > 0 && r > 0 && u > 0 && d > 0)
		{
			points++;
		}
	}
	display(points);
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
