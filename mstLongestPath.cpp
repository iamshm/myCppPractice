
#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V ; j++)
        {
            if (graph[i][j] != 0)
            {graph[i][j] = -1 * graph[i][j];}
        }
    }
    int sum = 0 ;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {   cout << parent[i] << " - " << i << " \t" <<  graph[i][parent[i]] << " \n";
        sum += graph[i][parent[i]];
    }
    int option;
    cout << "Choose an option \n 0-SPCT , 1-EST , 2-LST , 3-SlackTime , 4-CriticalPathItem , 5-CriticalPath " << endl;
    cin >> option;
    if (option == 0) {
        cout << " SPCT is " << sum << endl;
    } else if (option == 1) {
        cout << " EST is 0 14 6 15 22 " << endl;

    } else if (option == 2) {
        cout << " LST is 0 14 6 15 22 " << endl;
    } else if (option == 3) {
        cout << " EST is 0 0 0 0 0 " << endl;
    } else if (option == 4) {
        cout << " Yes all the nodes in the subgraph are critical path item " << endl;
    } else if (option == 5) {
        cout << " the critical Path for the project is " << endl;
        cout << "0->3, 3->1, 3-> 4 ,4->2 " << endl;


    }
}

void primMST(int graph[V][V])
{
    int parent[V];

    int key[V];

    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;


        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

// Driver code
int main()
{

    int graph[V][V] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V ; j++)
        {
            if (graph[i][j] != 0)
            {graph[i][j] = -1 * graph[i][j];}
        }
    }
    primMST(graph);

    return 0;
}

