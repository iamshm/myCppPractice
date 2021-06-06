/*more than n/k times
no of output will always be less than k-1 times

for n = 12 and k = 2
n/k = 6 so 7 7 times

12 =  7 + 5 <-- only 1(2-1 i.e k-1) possible

for n= 12 & k = 4
n/k = 3 so 4 times

12  =  4 + 4 + 4 <--only 3 possible (4-1 i.e. k-1) possible outputs

if a given number is a majority the minority can not shadow it

means majority > minority
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

struct eleCount {
	int ele;
	int count;
};
void nKtimes(vector<int> &a, int k) {
	int n = a.size();
	if (k < 2)return;
	struct eleCount temp[k - 1];
	for (int i = 0; i < k - 1; i++) {
		temp[i].count = 0;
	}
	for (int i = 0; i < a.size(); i++) {
		int j;
		//if a[i] is present in temp, increase count
		for (int j = 0; j < k - 1; j++) {
			if (temp[j].ele == a[j])
			{
				temp[j].count += 1;
				break;
			}
		}
		if (j == k - 1)
		{
			int l;
			for (int l = 0; l < k - 1; l++) {
				if (temp[l].count == 0)
				{
					temp[l].ele = a[i];
					temp[l].count = 1 ;
				}
			}
			if (l == k - 1)
				for (int l = 0; l < k - 1; l++) {
					temp[l].count -= 1;
				}
		}
	}

	for (int i = 0; i < k - 1; i++) {
		int ac = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] == temp[i].ele)
				ac++;
		}
		if (ac > n / k)
		{
			cout << temp[i].ele << "and count " << ac << endl;
		}
	}
}
int main()
{
	shm();
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	nKtimes(a, k);

}
/*
input
8 4
3 1 2 2 1 2 3 3
*/