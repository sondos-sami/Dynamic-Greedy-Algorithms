#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_nodes = 200000;

vector<pair<int, int>> graph[max_nodes];
int parent[max_nodes], node_size[max_nodes];

void initialize_set(int node) {
    parent[node] = node;
    node_size[node] = 1;
}

int find_parent(int node) {
    if (node == parent[node]) return node;
    return find_parent(parent[node]);
}

void merge_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (node_size[a] < node_size[b]) swap(a, b);
        parent[b] = a;
        node_size[a] += node_size[b];
    }
}

struct GraphEdge {
    int u, v, weight;
    GraphEdge(int u, int v, ll weight) : u(u), v(v), weight(weight) {}
    bool friend operator < (GraphEdge A, GraphEdge B) {
        return A.weight < B.weight;
    }
};

struct KruskalAlgorithm {
    int num_nodes;
    vector<GraphEdge> edges;
    KruskalAlgorithm(int _num_nodes) {
        num_nodes = _num_nodes;
        for (int i = 1; i <= num_nodes; ++i) initialize_set(i);
    }

    void add_edge(int u, int v, ll weight) {
        edges.push_back(GraphEdge(u, v, weight));
    }

    ll MST() {
        sort(edges.begin(), edges.end());
        ll total_weight = 0;
        for (auto edge : edges) {
            if (find_parent(edge.u) == find_parent(edge.v)) continue;
            merge_sets(edge.u, edge.v);
            graph[edge.u].emplace_back(edge.weight, edge.v);
            graph[edge.v].emplace_back(edge.weight, edge.u);
            total_weight += edge.weight;
        }
        return total_weight;
    }
};

int num_nodes, num_edges;
ll weight_count[max_nodes << 1], subtree_size[max_nodes], result[max_nodes << 1];

void dfs(int node, int parent_node) {
    subtree_size[node] = 1;
    for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
        int weight = it->first;
        int neighbor = it->second;

        if (neighbor == parent_node) continue;
        dfs(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
        weight_count[weight] += (subtree_size[neighbor] * 1LL * (num_nodes - subtree_size[neighbor]));
    }
}
