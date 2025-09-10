#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007

class DSU {
public:
    vector<int> parent, size, blackCount;
    
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        blackCount.resize(n + 1, 0); // Initialize black node count to 0 for all nodes
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union by size with blackCount adjustment
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            // Merge black node counts correctly after union
            blackCount[rootX] += blackCount[rootY];
        }
    }
    
    // Toggle the color of the node x
    void toggle(int x) {
        int rootX = find(x);
        // If it's black, make it white (decrease count), if it's white, make it black (increase count)
        blackCount[rootX] += (blackCount[rootX] == 0 ? 1 : -1);
    }
    
    // Check if the component containing node x has any black node
    bool hasBlackNode(int x) {
        return blackCount[find(x)] > 0;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    DSU dsu(N);
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {  // Type 1: Add an edge u-v
            int u, v;
            cin >> u >> v;
            dsu.unionSets(u, v);
        }
        else if (type == 2) {  // Type 2: Toggle color of node v
            int v;
            cin >> v;
            dsu.toggle(v);
        }
        else if (type == 3) {  // Type 3: Check if there's a black node in the component of v
            int v;
            cin >> v;
            if (dsu.hasBlackNode(v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
