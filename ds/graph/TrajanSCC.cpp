// Trajan algorithm
// Strongly connected components SCC
// https://www.youtube.com/watch?v=ZeDNSeilf-Y&t=2s
// discovery low time disc
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

int V = 6;

void DFStrajanSCC(int u, vector<int> &disc, vector<int> &low, stack<int> &stk, vector<bool> &presentInStack, vector<int> adj[]) {
	static int time = 0;
	low[u] = disc[u] = time;
	time++;
	stk.push(u);
	presentInStack[u] = true;

	for (int v : adj[u]) {
		if (disc[v] == -1) { // if not visited
			DFStrajanSCC(v, disc, low, stk, presentInStack, adj);
			low[u] = min(low[u], low[v]);
		} // if visited
		// differentiate between backedge n cross edge
		else if ( presentInStack[v] ) // back edge
			low[u] = min(low[u], disc[v]);
	}

	if (low[u] == disc[u]) // head node case
		// so printing scc
	{
		cout << "SCC is: ";
		while (stk.top() != u) {
			int element = stk.top();
			cout << element << " ";
			presentInStack[element] = false;
			stk.pop();
		}
		cout << stk.top() << " ";
		presentInStack[stk.top()] = false;
		stk.pop();
	}
}
void TrajanSCC(vector<int> adj[]) {
	vector<int> disc(V, -1), low(V, -1);
	vector<bool> presentInStack(V, false);
	stack<int> stk;

	for (int i = 0; i < V; i++) {
		if (disc[i] == -1) {
			DFStrajanSCC(i, disc, low, stk, presentInStack, adj);
		}
	}
}
void solve() {
	vector<int> adj[V];
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(0);
	adj[4].push_back(5);
	adj[4].push_back(6);
	adj[2].push_back(1);
	adj[5].push_back(6);
	adj[5].push_back(6);

	TrajanSCC(adj);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

