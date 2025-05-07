#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited);


int main() {

    vector<vector<int>> graph;
    // Example graph representation using adjacency list
    graph = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 3, 4}, // Node 1 is connected to nodes 0, 3, and 4
        {0},       // Node 2 is connected to node 0
        {1},       // Node 3 is connected to node 1
        {1}        // Node 4 is connected to node 1
    };

    // Print the graph visually
    cout << "Graph representation:" << endl;
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Perform BFS
    vector<bool> visited(graph.size(), false);
    int startNode = 0; // Starting node for BFS
    bfs(startNode, graph, visited); // Call the BFS function


    return 0;
}


void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visiting node: " << node << endl;

        for(int n: graph[node]) {
            if(!visited[n]){
                q.push(n);
                visited[n] = true;
            }
        }
    }
}