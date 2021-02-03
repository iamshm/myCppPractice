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
	int temp, n;
	cin >> n;

	std::vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	sort(v.begin(), v.end());
	int diff = 10001;
	for (int i = 0; i < n - 1; ++i)
	{
		diff = min(diff, (abs(v[i] - v[i + 1])));
	}
	display(diff);
	diff = 0;
	v.clear();

}
int main()
{
	shm();
	int tc = 1;
	cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}
