#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_stack(int start, vector<vector<int>>& graph, vector<bool>& visited);

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited);


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

    // Perform DFS
    vector<bool> visited(graph.size(), false);
    int startNode = 0; // Starting node for DFS
    cout << "DFS Traversal starting from node " << startNode << ":" << endl;
    dfs(startNode, graph, visited); // Call the recursive DFS function

    cout << "DFS Traversal using stack:" << endl;
    fill(visited.begin(), visited.end(), false); // Reset visited array
    dfs_stack(startNode, graph, visited); // Call the stack-based DFS function

}

// Recursive DFS function
void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[start] = true;

    for (int neighbor: graph[start]){
        if(visited[neighbor] == false) {
            visited[neighbor] = true;
            cout << "Visiting node: " << neighbor << endl;
            dfs(neighbor, graph, visited);
        }
    }
}

// 
void dfs_stack(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    // keeps track of new neighbors to visit
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << "Visiting node: " << node << endl;
        for(int n:graph[node]){
            if (!visited[n]) {
                visited[n] = true;
                s.push(n);
            }
        }
    }
}
