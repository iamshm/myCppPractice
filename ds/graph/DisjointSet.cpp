// Disjoint Set
// Union by Rank
// Path Compression

// Union TC O(4α) ~ O(4)

#include <bits/stdc++.h>
using namespace std;


int parent[100005];
int rank[100005];


void makeSet() {
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int findPar(int node) {
	if ( node == parent[node]) {
		return node;
	}
	return parent[node] = findPar(parent[node]);//path compression
}

void Union(int u, int v) {
	u = findPar(u);
	v = findPar(v);

	if (rank[u] < rank[v]) {
		parent[u] = v;
	} else if (rank[v] < rank[u]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		rank[u]++;
	}
}

void main() {
	makeSet();
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	if (findPar(2) != findPar(3)) {
		cout << "doesnt belong to same component";
	} else {
		cout << "belong to same component";
	}
}