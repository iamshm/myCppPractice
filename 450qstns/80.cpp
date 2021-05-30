//Rerrange characters such that no two adjacent are same
//https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

#include <bits/stdc++.h>
#include <queue>
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

 /* first add element with highest frequency in alternating position */
string rearrangedString(string s){
    vi freq(26,0);
    loop(i,0,s.size()-1) freq[s[i]-'a']++;
    int n = s.size();
    // get Max freq character
    int max = 0;
    char ch;
    loop(i, 0, 26-1){
        if(freq[i] > max){
            max =  freq[i];
            ch = 'a' + i;
        }
    }
    int maxCount =  max;
    if(!n) return "";
    if(maxCount > (n+1)/2) return "";
    // filling in  even slots
    string ans = s;
    int idx=0;
    while(maxCount){
        ans[idx] = ch;
        idx+=2;
        maxCount--;
        freq[ch-'a']--;
    }

    loop(i, 0, 25){
        while(freq[i] > 0){
            idx = (idx >= s.size() ) ? 1: idx;
            ans[idx] = 'a' + i;
            idx+=2;
            freq[i]--;
        }
    }
    return ans;
}

/* We use priority queue and use pus and pop to add elements alternately   */
string rearrangedStringUsingHeap(string s){
    int n = s.size();
    vi freq(256,0);
    priority_queue< pair<int, char>> pq;
    loop(i, 0, n-1) freq[s[i] - 'a']++;
    for(char ch = 'a'; ch <= 'z';ch++)
        if(freq[ch-'a'])
            pq.push(make_pair(freq[ch-'a'],ch));
    pair<int, char> prev,temp;
    prev.first = -1;
    prev.second = '#';
    string str = "";
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        str+=temp.second;

        if(prev.first >0)
            pq.push(prev);
        temp.first--;
        prev = temp;
    }
    if( n!= str.size()) return "";
    return str;
    
}
void solve(){
    string s;
    cin >> s;

    cout <<"Placing in Even spaces first"<< rearrangedString(s);
    cout << "\nUsing Heap Pair " << rearrangedStringUsingHeap(s);
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
