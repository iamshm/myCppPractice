//https://www.youtube.com/watch?v=Q3iTTwgDb6U
//Smallest distinct window
//Sliding window
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
    string s;
    cin >> s;
    set<char> unique;
    unordered_map<char,int> freq;
    loop(i,0,s.size()-1){
        unique.insert(s[i]);
    }
    int totalDistinct = unique.size();

    int i=0,j=1; //window size

    freq[s[i]]++; // freq of char present in current window
    int c = 0; // stores no of distinct char in current window
    c++;
    int minm = INT_MAX;

    while(i <= j and j < s.size()){
        if( c < totalDistinct) { //increase the size of window
            if(freq[s[j]] == 0 ) c++; // distict char found so increment
            // no of distinct char in window
            freq[s[j]]++;
            j++; // increment the window
        } else if (c == totalDistinct){ // if we have all the distinct char in the current 
            // window we try to minimise the size of window
            minm = min(minm,j-i);
            if(freq[s[i]] == 1)
                c--;
            freq[s[i]]--;
            i++; // decrement the window
        }
    }
    // This handles a corner case
    // say incase we found all distinct char on the last element 
    // then the above loop wont run 
    while(c==totalDistinct){
        minm = min(minm,j-i);
        if(freq[s[i]] == 1) c--;
        freq[s[i]]--;
        i++;
    }
    cout << minm << endl;
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
