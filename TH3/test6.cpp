#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

#define FI "test6.inp"
#define FO "test6.out"

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

vector<int> bfs(int start) {
    vector<int> com;
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        com.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return com;
}

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    int n;
    fi >> n;
    fi.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(fi, line);
        stringstream ss(line);
        int v;
        while (ss >> v && v != -1) {
            adj[i].push_back(v);
            adj[v].push_back(i); // vì đồ thị vô hướng
        }
    }

    vector<vector<int>> components;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components.push_back(bfs(i));
        }
    }

    fo << components.size() << endl;
    for (const auto& comp : components) {
        for (int v : comp) fo << v << " ";
        fo << endl;
    }

    fi.close();
    fo.close();
    return 0;
}