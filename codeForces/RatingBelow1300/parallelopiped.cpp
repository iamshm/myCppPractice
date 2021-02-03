//if area of sides are given (s1,s2,s3) then side a, b,c are sqrt(s18*s2/s3) and so on similarly
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
/*
input 4 6 6
*/

void solve() {
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	double a = sqrt(s1 * s2 / s3);
	double b = sqrt(s2 * s3 / s1);
	double c = sqrt(s1 * s3 / s2);
	double sum = a + b + c;
	display(sum * 4);
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
