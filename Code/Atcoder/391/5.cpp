#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& indices) {
    visited[node] = true;
    indices.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, indices);
        }
    }
}

vector<int> lexicographicallySmallestArray(int N, int M, vector<int>& A, vector<int>& L, vector<int>& R) {
    vector<vector<int>> adj(N);
    vector<bool> visited(N, false);

    // Build adjacency list from the given pairs
    for (int i = 0; i < M; i++) {
        adj[L[i]].push_back(R[i]);
        adj[R[i]].push_back(L[i]);
    }

    vector<int> result(A);
    
    // Traverse each connected component
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> indices, values;
            
            // Find all nodes (indices) in this component using DFS
            dfs(i, adj, visited, indices);

            // Extract values corresponding to these indices
            for (int idx : indices) {
                values.push_back(A[idx]);
            }

            // Sort both indices and values
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            // Place sorted values back in their original indices
            for (size_t j = 0; j < indices.size(); j++) {
                result[indices[j]] = values[j];
            }
        }
    }

    return result;
}

// Driver Code
int main() {
    int N = 8, M = 6;
    vector<int> A = {6, 11, 17, 17, 19, 11, 1, 10};
    vector<int> L = {0, 1, 2, 2, 2, 4};
    vector<int> R = {7, 5, 3, 6, 7, 7};

    vector<int> res = lexicographicallySmallestArray(N, M, A, L, R);
    
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}