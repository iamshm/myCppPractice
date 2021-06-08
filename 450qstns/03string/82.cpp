/* https://practice.geeksforgeeks.org/problems/print-anagrams-together/1 */
/* Print anagrams together */

#include <bits/stdc++.h> 
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
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
    int n;
    cin >> n;
    string s[n];
    vector<pair<string,int>> psi;
    loop(i,0,n-1) {
        cin >> s[i];
        psi.push_back(make_pair(s[i],i));
    }
    loop(i,0,n-1){
        string tmp = psi[i].first;
        sort(tmp.begin(),tmp.end());
        psi[i].first=tmp;
        debug(tmp);
    }
    string  test =  endl;
    sort(psi.begin(),psi.end());
    for(auto x:psi){
       cout << s[x.second] <<endl;
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
cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
return 0;
}