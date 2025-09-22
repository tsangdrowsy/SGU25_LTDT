#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;

#define FI "test2.inp"
#define FO "test2.out"

const int MAXN = 100000;
vector<int> adj[MAXN];
int color[MAXN]; // -1: chưa tô, 0 hoặc 1: màu

bool coPhanDoi(int start) {
    queue<int> q;
    color[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // hai đỉnh kề cùng màu
            }
        }
    }
    return true;
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

    fill(color, color + n + 1, -1); // chưa tô màu

    bool PhanDoi = true;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            if (!coPhanDoi(i)) {
                PhanDoi = false;
                break;
            }
        }
    }

    if (coPhanDoi) fo << "Do thi phan doi\n";
    else fo << "Do thi khong phan doi\n";

    fi.close();
    fo.close();
    return 0;
}