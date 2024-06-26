#include <iostream>
using namespace std;
const int INF = 1e9;

int minWeightEdge(int weights[], bool visited[], int V)
 {
    int minWeight = INF;
    int minIndex = -1;
    for (int i = 0; i < V; ++i)
	{
    	
        if (!visited[i] && weights[i] < minWeight) 
		{
            minWeight = weights[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[][100], int V)
 {
    int parent[V]; // To store the parent of each vertex
    int weights[V]; // To store the weight of the minimum edge to connect each vertex
    bool visited[V]; // To track visited vertices

    for (int i = 0; i < V; ++i)
	{
        parent[i] = -1;
        weights[i] = INF;
        visited[i] = false;
    }

    weights[0] = 0;

    for (int i = 0; i < V - 1; ++i)
	{
        int u = minWeightEdge(weights, visited, V);
        visited[u] = true;
        for (int v = 0; v < V; ++v)
		{
            if (graph[u][v] && !visited[v] && graph[u][v] < weights[v]) 
			{
                parent[v] = u;
                weights[v] = graph[u][v];
            }
        }
    }

    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100]; // Assuming a maximum of 100 vertices

    cout << "Enter the adjacency matrix representing the graph:\n";
    for (int i = 0; i < V; ++i)
	{
        for (int j = 0; j < V; ++j) 
		{
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
