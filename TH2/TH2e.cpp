#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<vector<int>> matrixToList(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adjMatrix[i][j])
                adjList[i].push_back(j);
    return adjList;
}
vector<pair<int, int>> matrixToEdges(const vector<vector<int>>& adjMatrix, bool directed = false) {
    int n = adjMatrix.size();
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adjMatrix[i][j]) {
                if (directed || i < j)
                    edges.emplace_back(i, j);
            }
    return edges;
}
vector<vector<int>> listToMatrix(const vector<vector<int>>& adjList, bool directed = false) {
    int n = adjList.size();
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (int u = 0; u < n; ++u)
        for (int v : adjList[u]) {
            adjMatrix[u][v] = 1;
            if (!directed)
                adjMatrix[v][u] = 1;
        }
    return adjMatrix;
}
vector<pair<int, int>> listToEdges(const vector<vector<int>>& adjList, bool directed = false) {
    int n = adjList.size();
    vector<pair<int, int>> edges;
    for (int u = 0; u < n; ++u)
        for (int v : adjList[u]) {
            if (directed || u < v)
                edges.emplace_back(u, v);
        }
    return edges;
}
vector<vector<int>> edgesToMatrix(const vector<pair<int, int>>& edgeList, int n, bool directed = false) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (auto [u, v] : edgeList) {
        adjMatrix[u][v] = 1;
        if (!directed)
            adjMatrix[v][u] = 1;
    }
    return adjMatrix;
}
vector<vector<int>> edgesToList(const vector<pair<int, int>>& edgeList, int n, bool directed = false) {
    vector<vector<int>> adjList(n);
    for (auto [u, v] : edgeList) {
        adjList[u].push_back(v);
        if (!directed)
            adjList[v].push_back(u);
    }
    return adjList;
}

int main() {
    n = 5;
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    cout << "Ma tran ke\n";
    for (auto& row : adjMatrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    auto adjList = matrixToList(adjMatrix);
    cout << "\n Danh sach ke\n";
    for (int i = 0; i < n; ++i) { 
        cout << i << ": ";
        for (int v : adjList[i]) cout << v << " ";
        cout << endl;
    }
    auto edgeList = matrixToEdges(adjMatrix);
    cout << "\n Danh sach canh \n";
    for (auto [u, v] : edgeList)
        cout << u << " - " << v << endl;
    auto matrixFromList = listToMatrix(adjList);
    cout << "\n Ma tran tu danh sach ke\n";
    for (auto& row : matrixFromList) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    auto edgesFromList = listToEdges(adjList);
    cout << "\nDanh sach canh tu danh sach ke\n";
    for (auto [u, v] : edgesFromList)
        cout << u << " - " << v << endl;
    auto matrixFromEdges = edgesToMatrix(edgeList, n);
    cout << "\n Ma tran tu danh sach canh \n";
    for (auto& row : matrixFromEdges) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    auto listFromEdges = edgesToList(edgeList, n);
    cout << "\n Danh sach ke tu danh sach canh\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : listFromEdges[i]) cout << v << " ";
        cout << endl;
    }
    return 0;
}