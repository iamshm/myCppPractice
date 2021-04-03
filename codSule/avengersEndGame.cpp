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
	int n ;
	cin >> n;
	int ans = 0;
	vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};
	// SieveOfEratosthenes( n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if ((i % prime[j]) == 0) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
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
/*
#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e5+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
vi adj[N];
int vis[N],par[N],a[N];

int primes[] = {2,3,5,7,11,13,17,19};

void go()
{
	cin>>n;
	int ans = 0;
	int noOfSubsets = (1<<8) ;

	fo(i,1,noOfSubsets)
	{
		int setBits = __builtin_popcount(i);
		int mask = 1;
		int denominator = 1;
		fo(j,0,8)
		{
			mask = 1<<j;
			if( (mask&i) )
			{
				denominator *= primes[j];
			}
		}
		if ( (setBits&1))
		{
			ans += n/denominator;
		}
		else
		{
			ans -= n/denominator;
		}
	}

	cout << ans << endl;

}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	test(t) go();
}
*/