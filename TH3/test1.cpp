#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

#define FI "test1.inp"
#define FO "test1.out"

const int MAXN = 100000;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
bool found = false;

void dfs(int u, int target) {
    visited[u] = true;
    if (u == target) {
        found = true;
        return;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, target);
            if (found) return; // dừng sớm nếu đã tìm thấy
        }
    }
}

int main() {
    int n, x, y;
    ifstream fi(FI);
    ofstream fo(FO);

    fi >> n >> x >> y;
    fi.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(fi, line);
        stringstream ss(line);
        int v;
        while (ss >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    fill(visited, visited + n + 1, false);
    fill(parent, parent + n + 1, -1);
    found = false;
    dfs(x, y);

    if (!visited[y]) {
        fo << "0\n"; // không có đường đi
        return 0;
    }

    vector<int> path;
    for (int cur = y; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    fo << path.size() << endl;
    for (int v : path) {
        fo << v << " ";
    }
    fo << endl;

    return 0;
}