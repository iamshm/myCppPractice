// Recursively remove all adjacents in a string
// https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/
/* https://www.youtube.com/results?search_query=Recursively+remove+all+adjacent+duplicates */
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
string removeAdjRecursively(string s) {
    string s2;
    int n = s.size(), l = 0, r, flag, last = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        flag = 0;
        while ((s[i] == s[j]) and j < n) {
            j++;
            flag = 1;
            last = 1;
        } // we traverse till we find duplicates

        if (flag == 1) {
            l = j; // we update the variables
            i = j; // as we had found duplicates
        } else {
            r = i;
            s2.append(s.substr(l, r - l + 1));
            l = j;
            i++;
        }
    }
    if (last) { // if previous string had duplicates we again repeat
        return removeAdjRecursively(s2);
    } else {
        return s2;
    }
}

void solve() {
    string s;
    cin >> s;
    cout << removeAdjRecursively(s);
}

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
