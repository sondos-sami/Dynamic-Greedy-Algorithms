 #include <bits/stdc++.h>

using namespace std;

struct Connection {
    int start, end;
    long long weightGold, weightSilver;
};

int nodes, edgesCount, goldMultiplier, silverMultiplier;
long long minimumCost;
vector<Connection> connections;
vector<Connection> selectedConnections;
vector<int> disjointSetParent;
const long long INFINITY_VALUE = LLONG_MAX;

int findSet(int node) {
    if (node == disjointSetParent[node])
        return node;
    return disjointSetParent[node] = findSet(disjointSetParent[node]);
}

void initializeDisjointSet() {
    for (int i = 1; i <= nodes; ++i)
        disjointSetParent[i] = i;
}

bool compareConnections(const Connection &a, const Connection &b) {
    if (a.weightGold != b.weightGold)
        return a.weightGold < b.weightGold;
    return a.weightSilver < b.weightSilver;
}

void performKruskal() {
    int selectedCount = 0;
    minimumCost = INFINITY_VALUE;
    for (int i = 0; i < edgesCount; ++i) {
        initializeDisjointSet();
        selectedConnections.push_back(connections[i]);
        long long maxSilverWeight = -INFINITY_VALUE;

         
        sort(selectedConnections.begin(), selectedConnections.end(), [](const Connection &a, const Connection &b) {
            return a.weightSilver < b.weightSilver;
        });

        int edgesUsed = 0;
        for (size_t j = 0; j < selectedConnections.size(); ++j) {
            int setU = findSet(selectedConnections[j].start);
            int setV = findSet(selectedConnections[j].end);
            if (setU != setV) {
                maxSilverWeight = max(maxSilverWeight, selectedConnections[j].weightSilver);
                selectedConnections[edgesUsed++] = selectedConnections[j];
                disjointSetParent[setU] = setV;
            }
            if (edgesUsed == nodes - 1)
                break;
        }

        if (edgesUsed == nodes - 1) {
            minimumCost = min(minimumCost, connections[i].weightGold * goldMultiplier + maxSilverWeight * silverMultiplier);
        }
        selectedConnections.resize(edgesUsed);
    }
}

