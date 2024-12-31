//
// Created by Dell on 24/12/2024.
//
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    // Constructor
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union operation by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    UnionFind uf(n);

    // Union all connected nodes
    for (const auto& edge : edges) {
        uf.unite(edge[0], edge[1]);
    }

    // Check if source and destination are in the same component
    return uf.find(source) == uf.find(destination);
}

void solveGraphProblem() {
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;

    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges;
    cout << "Enter the edges (format: u v for each edge):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "Enter the destination vertex: ";
    cin >> destination;

    if (validPath(n, edges, source, destination)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

