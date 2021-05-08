// https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
#define ll long long
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

const int N = 105;
const int W = 100005;
vector<vector<ll>> dp(N, vector<ll> (W, -1)); //dp[index][weight] = max Value
ll n, c;
ll w[N], v[N];

ll knapsack1(ll position, ll capacityLeft) {
	if (position == n ) return 0;
	if (dp[position][capacityLeft] != -1) return dp[position][capacityLeft];
	ll ans = 0;

	//take
	if (capacityLeft - w[position] >= 0) //if we have capacity, we take
		ans = max(ans, knapsack1(position + 1, capacityLeft - w[position]) + v[position]);

	//not take
	ans = max(ans, knapsack1(position + 1, capacityLeft));
	//memoization
	return dp[position][capacityLeft] = ans;
}

int main()
{
	shm();
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cout << knapsack1(0, c);
}