// https://atcoder.jp/contests/dp/tasks/dp_p

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

vector<int> tree[100005]; // array of vectors
ll dp[100005][2];

ll independentSet(int node,int parent, int c){ //c -> color or constraint
	if(dp[node][c] !=-1) return dp[node][c];
	ll ans = 0;
	ll w0 = 1;//ways without constraint/color
	for(auto child : tree[node]){
		if(child != parent)
			w0 = (w0 * independentSet(child, node,0))%MOD;
	}
	ans+=w0
;	ll w1=1;
	if(not c){
		for(auto child : tree[node]){
			if(child != parent)
				w1 = (w1 * independentSet(child, node,1))%MOD;
		}
		ans = (ans%MOD + w1%MOD)%MOD;
	}
	return dp[node][c] = ans;
}
void solve(){
 	int n;
 	cin >> n;
 	loop(i,0,n-2){
 		int x,y;
 		cin >> x>> y;
 		tree[x].push_back(y);
 		tree[y].push_back(x);
 	}
 	memset(dp,-1,sizeof(dp));
 	cout << independentSet(1,-1,0);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}