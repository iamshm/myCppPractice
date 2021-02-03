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
	int temp = 3;
	vector<long long> a(4);
	for (auto &x : a ) { cin >> x ;}

	sort(a.begin(), a.end());
	// for (auto &x : a ) { display(x);}
	for (int i = 1; i < 4; i++) {
		// debug(a[i]);
		if (a[i - 1] != a[i])
		{
			temp--;
		}

	}
	display(temp);

}
//input 1 7 3 3
//input 7 7 7 7
//input 251590420 586975278 916631563 586975278


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
