#include <bits/stdc++.h>
using namespace std;

void bfs(int n,vector<int> adj[]){
    cout << "\n BFS Traversal\n";
    vector<int> bfs;
    vector<int> visited(n+1,0);
    int components = 0;
    for(int i = 1 ;i <=n;i++){
        if(!visited[i]){
            components++;
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                /* bfs.push_back(node); */
                cout << node <<" ";
                for(auto it : adj[node]){
                    cerr << it << endl;
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        cout << endl;
        }
    }
    /* for(auto &it : bfs){ */
    /*     cout << it<<  " "; */
    /* } */
    cout <<"\n No of components" << components << endl;
}

void dfs(int node, vector<int> &visited,vector<int> adj[],vector<int> &dfsOutput){
    cout << node << " ";
    visited[node]=1;
    dfsOutput.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited,adj,dfsOutput);
        }
    }
}
void dfsOfGraph(int V, vector<int> adj[]){
    cout << "\n DFS Traversal\n";
    vector<int> dfsOutput;
    vector<int> visited(V+1,0);
    int components = 0;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            components++;
            dfs(i,visited,adj,dfsOutput);
            cout << endl;
        }
    }
    cout << "\n No of components"<<  components;
    cerr << "HElllo";
}
// Input
// 10 8
// 1 3
// 1 6
// 6 4
// 3 4 
// 6 8
// 2 9
// 5 7
// 7 10

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
        cerr << u<< "->"  << v << " ";
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(n,adj);
    dfsOfGraph(n,adj);
    return 0;

}
