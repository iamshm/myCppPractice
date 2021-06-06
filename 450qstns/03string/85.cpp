/* Wildcard String Matching */
/* https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1 */

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define inf INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define vi vector<ll>
const int MOD = 1e9 + 7;
#define loop(i,a,b) for(int i =(a);i<=(b);i++)
#define looprev(i,a,b) for(int i = (a);i>=b;i--)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------*/

void solve() {
    string pattern, text;
    cin >> text >> pattern;
    int t = text.size();
    int p = pattern.size();
    int dp[p + 1][t + 1];
    for (int i = p; i >= 0; i--) {
        for (int j = t; j >= 0; j--)
        {
            if (i == p and j == t) dp[i][j] = 1;
            else if (i == p) dp[i][j] = 0;
            else if (j == t)
            {
                if (pattern[i] == '*') {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = 0;
                }
            } else {
                if (pattern[i] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (pattern[i] == '*') {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                } else if (pattern[i] == text[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {

                    dp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= t; j++)
        {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    if (dp[0][0] == 1 ) cout << true;
    else cout << false;
}


// Input
// abaaabab
// ab*a?
// geeksforgeeks
// ge?ks*
// baaabab
// ba*a?
int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
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

