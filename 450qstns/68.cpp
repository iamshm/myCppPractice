//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
//https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
//All Pallindromic substrings
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

int allPalindromicSubs(string s){
    int n = s.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    // each char is a palindrome itself
    loop(i, 0, n-1){
        dp[i][i] = 1;
    }

    loop(i,2,n){
        loop(j,0,n-i) {
            int k = j+ i-1;
            if(s[j] == s[k]) {
                dp[j][k] = dp[j][k-1] + dp[j+1][k] +1 ;
            }else {
                dp[j][k] = dp[j][k-1] + dp[j+1][k] - dp[j+1][k-1] ;
            }
        }
    }

    //dp
    loop(i, 0, n-1) {
        loop(j, 0, n-1) {
            cerr << dp[i][j] <<" ";
        }
        cerr<< endl ;
    }
    return dp[0][n-1];
}
void solve(){
    string s;
    cin >> s;
    cout << allPalindromicSubs(s);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/mnt/d/cpp/Error.txt", "w", stderr);
#endif
    fastio();
    clock_t begin = clock();

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}

