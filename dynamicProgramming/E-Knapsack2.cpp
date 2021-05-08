// https://atcoder.jp/contests/dp/tasks/dp_e
// Just another solution - https://pastebin.com/t9ecXjDt

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
const int V = 100005;
vector<vector<ll>> dp(N, vector<ll> (V, -1));  //dp[index][value] = minm weight
ll n, c;
ll w[N], v[N];

ll kanpsack2(ll position, ll val) {
	if (position == n ) return val == 0 ? 0 : INT_MAX;

	if (dp[position][val] != -1) return dp[position][val];

	//not take
	ll  ans = kanpsack2(position + 1, val);
	//take
	if (v[position] <= val) //if we have capacity, we take
		ans = min(ans, kanpsack2(position + 1, val - v[position]) + w[position]);

	//memoization
	return dp[position][val] = ans;
}
// we can approach it like
// min weight required to gain certain amount of value

//here 1 <= v <= 1000
//so if every n element has 1000 value maxV that we can have 100 * 1000 = 100000
int main()
{
	shm();
	cin >> n >> c;
	int maxV = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		maxV += v[i];
	}
	// for every posssible value finding the minm weight
	for (ll i = maxV; i > 0; i--) {
		if (kanpsack2(0, i) <= c ) {
			cout << i;
			break;
		}
	}

}