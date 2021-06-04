#include <bits/stdc++.h>
using namespace std;

// Cycle detection using dfs
bool dfsCheckCycle(int node,int parent,vector<int> adj[],vector<bool> &visited){
	visited[node] = true;
	for(auto it : adj[node]){
		if(!visited[it]){
			if(dfsCheckCycle(it,node,adj,visited)) return true;
		}else if (visited[it] and parent != it)
		{
			return true;
		}
	}
	return false;
}
void dfsCycleDetection(int V,vector<int> adj[]){
	bool found=false;
	vector<bool> visited(V+1,false);
	for(int i =1;i <=V;i++){
		if(!visited[i]){
			if(dfsCheckCycle(i,-1,adj,visited)){
			cout << "Cycle Found"<< endl;
				found = true;
				break;	
			}
		}
	}
	if(!found) cout << "Not found \n";

}

// Cycle detection using bfs
bool bfsCheckCycle(int n,int V,vector<int> adj[],vector<bool> &visited){
	queue<pair<int,int>> q;
	q.push({n,-1}); //creating q with nod enad its parent
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto it: adj[node]){ // exploring every neighbour of current node
			if(!visited[it]){
				visited[it] = true;
				q.push({it,node}); // pushing unvisited neighbours to queue and visiting them 
			}else if(visited[it] and parent!=it){
				return true; // but if the neighbour is visited
				// and the neighbour was not its parent means
				// there is a cycle
			}
		}
	}
	return false;
}
void bfsCycleDetection(int V,vector<int> adj[]){
	bool found =false;
	vector<bool> visited(V+1,false);
	for(int i = 1 ;i <=V ;i++){
		if(!visited[i]){
			if(bfsCheckCycle(i,V,adj,visited)) {
				cout << "Cycle Found"<< endl;
				found = true;
				break;
			}
				cout << endl;
		}
	}
	if(!found) cout << "Not found \n";
}
// Input
// 11 10
// 1 2
// 2 4
// 3 5
// 5 6
// 6 7
// 7 8
// 5 10
// 10 9
// 9 8
// 8 11

// Input
// 8 7
// 1 3
// 3 4
// 2 3
// 3 8
// 3 6
// 8 7 
// 7 6
int main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\Error.txt", "w", stderr);
#endif
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i= 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        cerr << u<< "->"  << v << "\n";
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bfsCycleDetection(n,adj);
    dfsCycleDetection(n,adj);
    return 0;

}