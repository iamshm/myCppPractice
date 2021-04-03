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
bool isPrime(int n)
{
	// Corner cases
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
int nextPrime(int N)
{
	if (N <= 1)
		return 2;

	int prime = N;
	bool found = false;
	while (!found) {
		prime++;

		if (isPrime(prime))
			found = true;
	}


	return prime;
}

vector<int> getNPrime(int n) {
	vector<int> ans;
	ans.push_back(2);
	int i = 2;
	int sim = 0 ;
	while (sim <= n) {
		int temp = nextPrime(i);
		ans.push_back(temp);
		i++;
		sim++;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> nPrimes = getNPrime(n);
	for (auto x : nPrimes ) { cout << x << endl; }

}

int main()
{
	shm();
	int tc ;
	cin >> tc; //no of test cases

	while (tc != 0) {
		solve();//driver function
		tc--;
	}
}
