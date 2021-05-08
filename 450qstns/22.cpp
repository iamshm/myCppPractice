//factorial of a large number

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000000007
#define inf 1e18
#define MAX 100000
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int multiply(int num, int ans[], int ansLen) {
	int carry = 0;
	for (int i = 0; i < ansLen; i++) {
		int product = ans[i] * num + carry;
		ans[i] = product % 10;
		carry = product / 10;
	}
	while (carry) { // if we carry it means the no of digits has increased so we insert a digit of ans in new index
		ans[ansLen] = carry % 10 ;
		carry /= 10;
		ansLen++;
	}
	return ansLen;
}
void factorialLargeNumber(int n) {
	int ans[MAX];
	int ansLen = 1 ;
	ans[0] = 1;

	for (int i = 2 ; i <= n; i++)
		ansLen = multiply(i, ans, ansLen);

	for (int i = ansLen - 1; i >= 0; i--) {
		cout << ans[i];
	}
	return ;
}
int main()
{
	shm();
	int n;
	cin >> n;
	factorialLargeNumber(n);
}