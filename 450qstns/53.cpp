#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 1e18
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

void solve() {
	int n;
	cin >> n;
	if (n == 1) { cout << "1"; return;}
	if (n == 2) { cout << "11"; return;}
	string s = "11";
	loop(i, 3, n) {
		string t = "" ;
		s = s + '$';
		int count  = 1;
		loop(j, 1, s.size() - 1) {
			if (s[j - 1] == s[j]) count++;
			else {
				t = t + to_string(count);
				t = t + s[j - 1];
				count = 1;
			}
		}
		s = t;
	}
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t begin = clock();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}