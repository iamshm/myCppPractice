// Parnanthesis checker
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x) cout << #x<<" "; cout << x; cout << endl;
#define endl '\n'
#define inf INT_MAX
#define ll long long
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

bool solve() {
	string x;
	cin >> x;
	char a;
	stack<char> s;
	loop(i, 0, x.size() - 1) {
		if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
			s.push(x[i]);
			continue;
		}
		if (s.empty())
			return false;

		switch (x[i]) {
		case ')':
			a = s.top();
			s.pop();
			if (a == '{' || a == '[')
				return false;
			break;
		case '}':
			a = s.top();
			s.pop();
			if (a == '(' || a == '[')
				return false;
			break;
		case ']':
			a = s.top();
			s.pop();
			if (a == '{' || a == '(')
				return false;
			break;
		}
	}
	return s.empty();
}

int main() {
	fastio();
	clock_t begin = clock();

	int t = 1;
	//cin >> t;
	while (t--) {
		cout << (solve());
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}