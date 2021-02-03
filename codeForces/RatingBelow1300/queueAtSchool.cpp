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
	int n, time;
	char temp;
	cin >> n >> time;
	char arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < time; j++)
	{

		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 'B' && arr[ i + 1] == 'G')
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				i++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << (arr[i]);
	}

}

int main()
{
	shm();
	int tc = 1;
	// cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}
