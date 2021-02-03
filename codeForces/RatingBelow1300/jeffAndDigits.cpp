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
	cin >> temp;
	int noOf5 = 0;
	int noOf0 = 0;
	for (int i = 0; i < temp; i++) {
		cin >> n;
		if (n == 5) noOf5++;
		if (n == 0) noOf0++;

	}
	if (noOf0 == 0) { //no 0 means not possible because 90 = 9 * 10
		cout << -1 << endl;
	} else if (noOf5 < 9)
	{
		cout << 0 << endl;
	} else {
		int numberOf5inNumber = ( noOf5 / 9) * 9;//if nof5 = 9 then numberOf5inNumber =9 also when noOf5= 10 or 11 ....17 then too numberOf5inNumber =9

		for (int i = 0; i < numberOf5inNumber; i++) cout << 5;
		for (int i = 0; i < noOf0; i++) cout << 0;
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
