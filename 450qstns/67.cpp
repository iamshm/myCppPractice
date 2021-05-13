//https://docs.google.com/spreadsheets/d/1IjjZF24YfEHHfcGZ1ADaGY7ZVkuI-cGJ/edit#gid=1898312341
// Minimum reversals to balanced expression
// https://www.youtube.com/watch?v=8q1sma-qMsA
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

int minReversalsUsingStack(string s){
    int n = s.size();
    if(n%2 != 0) return -1;
    stack<char> stk;
    loop(i, 0, n-1){
        if(s[i] == '}' && !stk.empty()){ //if we get closing bracket
            //then we check if it has a pair or not
            if (stk.top() == '{'){ // we pop as it has a pair means balanced
                stk.pop();
            }else { //we push if no pair available
                stk.push(s[i]);
            }
        }else{ // if we have opening bracket we push to stack
            stk.push(s[i]);
        }
    }
    int lenOfStringAfterRemovingBalanced = stk.size();
    // lenOfStringAfterRemovingBalanced will have equal no of opening and closing brackets

    int openBracket = 0;
    //calculating openingBrackets
    while(!stk.empty() && stk.top() == '{'){
        stk.pop();
        openBracket++;
    }
    int closingBracket = lenOfStringAfterRemovingBalanced - openBracket;

    return (ceil((double)openBracket/2) + ceil((double)closingBracket/2));

}

int minReversalWithoutStack(string s){
    int ans =0 ;
    int n = s.size();
    int open =0 ;
    int close =0;
    loop(i, 0, n-1){
        if(s[i] == '{') open++; //if opening bracket add its count
        else{ //if closing bracket 
            if(!open)close++; //inc its count if no open brackets
            else open --; //dec open count as we found a mtching close
        }
    }
    ans = (close/2) + (open/2);

    //following will be 1 if any was odd
    close%=2;
    open%=2;

    if(close)  ans+=2;
    return ans;
}
void solve(){
    string s;
    cin >> s;
    //cout << minReversalsUsingStack(s);
    cout << minReversalWithoutStack(s);
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

