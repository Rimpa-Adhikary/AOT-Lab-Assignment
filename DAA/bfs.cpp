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
// Function to perform BFS traversal
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Visit all unvisited neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    readGraph();      
    int startNode = 0; 
    bfs(startNode);   
    return 0;
}

