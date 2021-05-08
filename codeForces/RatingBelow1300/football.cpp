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
	map<string, int> noOfGoals;
	int n;
	cin >> n;
	string s;
	while (n > 0) {
		cin >> s;
		noOfGoals[s]++;
		n--;
	}
	int maxGoals = 0; string winner;
	for (auto it = noOfGoals.begin(); it != noOfGoals.end(); it++) {
		if (it->second > maxGoals)
		{
			maxGoals = it->second;
			winner = it->first;
		}
	}
	display(winner);
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
