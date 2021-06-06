//Longest Common Prefix
//https://www.geeksforgeeks.org/longest-common-prefix-using-word-by-word-matching/
//https://www.geeksforgeeks.org/longest-common-prefix-using-binary-search/
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

string commonPrefixByWordMatching(string s1, string s2){
    // follows associativity property
    // LCP(string1, string2, string3) 
    // = LCP (LCP (string1, string2), string3)
    string result;
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i =0,j=0; i < n1 and j < n2 ;i++,j++) {
        if(s1[i] != s2[j])
            break;
        result.push_back(s1[i]);
    }
    return result;
}

void solve(){
    int n;
    cin >> n;
    cerr << n;
    string a[n];
    loop(i, 0, n-1) cin >> a[i];

    // Word by word matching
    string prefix = a[0];
    loop(i,1,n-1){
        prefix = commonPrefixByWordMatching(prefix,a[i]);
        cerr << prefix<<endl;
    }
    cout << prefix <<endl;

    // Binary Search 
    
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

//Input
//3
//apple
//ape
//april
