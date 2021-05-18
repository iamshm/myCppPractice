// Boyer Moore Algo
// Pattern Matching
// https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
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

void solve(){
    string text  = "AABACCAABAABA";
    string pat ="AABA" ;
    unordered_map<char,int> badMatchTable;
    int patLen =pat.size();
    int textLen =text.size();

    // for 0 to n-2 max(1,patlen-index-1)
    loop(i,0,patLen-2){
        badMatchTable[pat[i]] = max(1,patLen-i-1);
    }
    // for n-1 value will be patLen (for last char)
    badMatchTable[pat[patLen-1]] = patLen;

    //see badMatchTable
    for(auto &x : badMatchTable){
        cerr << x.first << " " << x.second;
        cerr <<endl;
    }
    debug(pat);
    int idx = 0;

    while(idx <= textLen - patLen){
        int j = patLen-1;
        while(j >= 0 and text[idx+j] == pat[j]){
            j--;
        }
        if(j<0) {
            cout << "Pattern at  "<< idx <<endl;
            idx+=patLen;
        }else{
            if(badMatchTable.find(text[idx+j]) != badMatchTable.end()){
                idx+=badMatchTable[text[idx+j]];
            }else{
                idx+=patLen;
            }
        }
    }
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


