// Prim's MST
//  minimum spanning tree
// we find the edge with min wt that doesnot form a cycle
// and that node to the mst set update its parent
//


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


void primMST(vector<pair<int, int>> adj[], int n) {
	vector<int> parent(n, -1);
	vector<bool> mstSet(n, false);
	vector<int> key(n, INT_MAX);

	// minHeap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// pq --> key (weight) , vertex
	key[0] = 0; // node 0 has 0 wt
	parent[0] = -1; // parent of 0 is -1
	pq.push({0, 0});// src node with 0 weight;

	for (int i = 0; i < n - 1; ++i) // n-1 times bcoz src is already included
	{
		// we find the min edge
		int u = pq.top().second;
		pq.pop();

		mstSet[u] = true; // include it to mst set

		for (auto it : adj[u]) {
			int v = it.first;
			int weight = it.second;

			if (!mstSet[v] and weight < key[v]) {
				//it takes care of        this finds
				//not forming cycle		   min edge
				parent[v] = u; //update parent
				key[v] = weight; // update wt
				pq.push({key[v], v}); //push to priority queue
			}
		}
	}

	for (int i = 1; i < n; ++i)
	{
		cout << parent[i] << "<-->" << i << endl; //printing the mst
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	// 0 based index graph
	vector < pair<int, int >>adj[n];
	for (int i = 0; i < m; ++i)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
		adj[y].push_back({x, wt});
	}
	//Dijsktra is based on mst butwith fewchanges

	primMST(adj, n);
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

// 5 6
// 0 1 2
// 0 3 6
// 1 3 8
// 1 4 5
// 1 2 3
// 4 2 7