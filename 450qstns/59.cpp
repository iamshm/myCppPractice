//Word wrap problem
// https://www.geeksforgeeks.org/word-wrap-problem-dp-19/https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
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


int printSolution (int p[], int n)
{
	int k;
	if (p[n] == 1)
		k = 1;
	else
		k = printSolution (p, p[n] - 1) + 1;
	cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
	return k;
}
void wordWrap(int n, int k, vi a) {
	//calculating spaces
	int extraSpaces[n + 1][n + 1];
	memset(extraSpaces, 0, sizeof(extraSpaces));
	loop(i, 1, n) {
		extraSpaces[i][i] = k - a[i - 1];
		loop(j, i + 1, n) {
			extraSpaces[i][j] = extraSpaces[i][j - 1] - a[j - 1] - 1;
			// the extra space available from prev word
			//- the space occ by the crrent word
			//- 1 space betwwn words
		}
	}
	//calculating cost
	int cost[n + 1][n + 1];
	memset(cost, 0, sizeof(cost));
	loop(i, 1, n) {
		loop(j, i, n) {
			if (extraSpaces[i][j] < 0)
				//negative extraspace means there are more than
				//k chars in that line
				cost[i][j] = inf;
			else if (j == n and extraSpaces[i][j] >= 0)
				//if there is space after lasst word we dont count it
				cost[i][j] = 0;
			else
				// we square the space to get cost
				cost[i][j] = extraSpaces[i][j] * extraSpaces[i][j];
		}
	}
	int c[n + 1]; // c[i] will have optilmal cost from 1 to i
	int p[n + 1]; // this will have optimal arrangemnt
	c[0] = 0;
	//this will find minm cost and minm cost arrangement from 1 to j
	loop(j, 1, n) {
		c[j] = inf;
		loop(i, 1, j) {
			if (c[i - 1] != inf and cost[i][j] != inf and (c[i - 1] + cost[i][j] < c[j])) {
				c[j] = c[i - 1] + cost[i][j] ;
				p[j] = i;
				// cout << c[j] << "p" << p[j] << endl;
			}
		}
	}
	printSolution(p, n);
}


void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	loop(i, 0, n - 1) cin >> a[i];
	wordWrap(n, k, a);
}


int main() {
	fastio();
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
// Tutorial https://www.youtube.com/watch?v=RORuwHiblPc