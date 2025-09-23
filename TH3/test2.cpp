#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#define FI "test2.inp"
#define FO "test2.out"

const int MAXN = 100005;
vector<int> adj[MAXN];
int color[MAXN]; // -1: chưa tô, 0 hoặc 1: màu
bool coPhanDoi = true;

void dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == -1) {
            dfs(v, 1 - c);
            if (!coPhanDoi) return;
        } else if (color[v] == color[u]) {
            coPhanDoi = false;
            return;
        }
    }
}

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    int n, x, y;
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

    fill(color, color + n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            dfs(i, 0);
            if (!coPhanDoi) break;
        }
    }

    if (coPhanDoi) fo << "Do thi phan doi\n";
    else fo << "Do thi khong phan doi\n";

    fi.close();
    fo.close();
    return 0;
}