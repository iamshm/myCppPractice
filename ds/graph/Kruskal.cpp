// Kruskal
// spanning tree


// store graph in linear ds

// sort all edges acc to weight

// greedily pick shortest edge such that they dont belong to same component
// (usiing findPar) it will avoid cycles (as component belonging to
// same parent will lead to cycles)


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

struct node {
	int u, v, wt;
	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
}; // creating datatype

bool comp(node a, node b) {
	return a.wt < b.wt;
}
// disjoint set find Parent
int findPar(int u, vector<int> &parent) {
	if (u == parent[u]) return u;
	return parent[u] = findPar(parent[u], parent); //path compression
}

// Union by rank
void Unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
	u = findPar(u, parent);
	v = findPar(v, parent);

	if (rank[u] < rank[v]) {
		parent[u] = v;
	} else if (rank[v] < rank[u]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		rank[u]++;
	}
}

void KruskalMST() {
	int n, m;
	cin >> n >> m;

	vector<node> edges;

	for (int i = 0; i < m; ++i)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}

	sort(edges.begin(), edges.end(), comp);

	// disjoint set
	vector<int> parent(n + 1), rank(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		parent[i] = i; // makeSet()

	int cost = 0;

	vector<pair<int, int>> mst;
	for (auto it : edges) {
		if (findPar(it.u, parent) != findPar(it.v, parent)) {
			cost += it.wt;
			mst.push_back({it.u, it.v});
			Unionn(it.u, it.v, parent, rank);
		}
	}

	cout << "Cost of making Kruskal's MST " << cost << endl;
	for (auto it : mst) {
		cout << it.first << " <--> " << it.second << endl;
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
	fastio();

	int t = 1;
	//cin >> t;
	while (t--) {
		KruskalMST();
	}

	return 0;
}

// 6 9
// 5 4 9
// 5 1 4
// 1 4 1
// 1 2 2
// 4 2 3
// 4 3 5
// 3 2 3
// 3 6 8
// 2 6 7