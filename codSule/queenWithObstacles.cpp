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
int range(int n, int x, int y)
{
	return (x <= n && x > 0 && y <= n && y > 0);
}
int check(int n, int x, int y, int xx, int yy,
          map <pair<int, int>, int> mp)
{
	int ans = 0;
	while (range(n, x, y) && ! mp[ {x, y}])
	{
		x += xx;
		y += yy;
		ans++;
	}
	return ans;
}

int numberofPosition(int n, int k, int x, int y,
                     int obstPosx[], int obstPosy[])
{
	int x1, y1, ans = 0;
	map <pair<int, int>, int> mp;
	while (k--)
	{
		x1 = obstPosx[k];
		y1 = obstPosy[k];

		mp[ {x1, y1}] = 1;
	}
	ans += check(n, x + 1, y, 1, 0, mp);
	ans += check(n, x - 1, y, -1, 0, mp);
	ans += check(n, x, y + 1, 0, 1, mp);
	ans += check(n, x, y - 1, 0, -1, mp);
	ans += check(n, x + 1, y + 1, 1, 1, mp);
	ans += check(n, x + 1, y - 1, 1, -1, mp);
	ans += check(n, x - 1, y + 1, -1, 1, mp);
	ans += check(n, x - 1, y - 1, -1, -1, mp);

	return ans;
}

void solve() {
	int n;
	cin >> n;
	int qx, qy;
	cin >> qx >> qy;
	int noOfObstacles;
	cin >> noOfObstacles;
	int posX[noOfObstacles];
	int posY[noOfObstacles];
	for (int i = 0; i < noOfObstacles; i++) {
		cin >> posX[i] >> posY[i];
	}
	cout << numberofPosition(n, noOfObstacles, qx, qy,
	                         posX, posY) << endl;
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
