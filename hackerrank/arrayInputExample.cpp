#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;

	cin >> a >> b;

	vector<int> v2;
	vector<int> v1;

	while (a > 0) {
		int i;
		cin >> i;
		v1.push_back(i);
		a--;
	}


	while (b > 0) {
		int i;
		cin >> i;
		v2.push_back(i);
		b--;
	}


	for (int i : v1)cout << i << endl;
	cout << "Now arrb" << endl;
	for (int i : v2)cout << i << endl;





}
