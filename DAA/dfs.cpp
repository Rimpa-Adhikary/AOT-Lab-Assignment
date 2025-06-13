#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int graph[100][100];     // Adjacency matrix
bool visited[100];       // Track visited nodes
int n;                   // Number of vertices
void readGraph()
{
	fstream input;
	input.open("graph.txt",ios::in);
	input>>n;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			input>>graph[i][j];
		}
	}
	input.close();
}
void dfs(int node) {
    visited[node] = true;         // Mark current node as visited
    cout << node << " ";       
    // Visit all connected unvisited nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);               // Recursively visit the neighbor
        }
    }
}

int main() {
    readGraph();           
    int startNode = 0;     
    cout << "DFS traversal starting from node " << startNode << ": ";
    dfs(startNode);       
    cout << endl;
    return 0;
}
