//Count of given string in a 2D char array
//https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/
// recursive approach
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
char a[100][100];
int searchWord(int row,int col, string s,int rowMax,int colMax,int idx){
    int found=0;
    if(row>=0 and row <=rowMax and col >=0 and col <=colMax and s[idx] == a[row][col]){
        char temp = s[idx];
        idx++;
        a[row][col] =0;//to prevent selfloop
        if(idx == s.size()) found = 1;
        else {
            found+=searchWord(row, col+1, s, rowMax, colMax, idx);
            found+=searchWord(row, col-1, s, rowMax, colMax, idx);
            found+=searchWord(row+1, col, s, rowMax, colMax, idx);
            found+=searchWord(row-1, col, s, rowMax, colMax, idx);
        }
        a[row][col] = temp;//backtrack
    }
    return found;
}

void solve(){
    int n;
    cin >> n;
    loop(i, 0, n-1){
        loop(j,0,n-1)
            cin >> a[i][j];
    }
    string s;
    cin >> s;
    int found = 0;
    loop(i,0,n-1){
        loop(j,0,n-1){
            found+= searchWord(i,j,s,n-1,n-1,0);
        }
    }
    cout << found;
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
//6
//D D D G D D
//B B D E B S
//B S K E B K
//D D D D D E
//D D D D D E
//D D D D D G
//GEEKS
