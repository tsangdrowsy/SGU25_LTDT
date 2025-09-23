#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

#define FI "test7.inp"
#define FO "test7.out"

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, x, y, z;

void bfs(int start, int boCanhX = -1, int boCanhY = -1, int boNut = -1) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (visited[v]) continue;
            if ((u == boCanhX && v == boCanhY) || (u == boCanhY && v == boCanhX)) continue;
            if (v == boNut) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

int demPhanTu(int boCanhX = -1, int boCanhY = -1, int boNut = -1) {
    fill(visited, visited + n + 1, false);
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && i != boNut) {
            bfs(i, boCanhX, boCanhY, boNut);
            count++;
        }
    }
    return count;
}

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    fi >> n >> x >> y >> z;
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

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (find(adj[v].begin(), adj[v].end(), u) == adj[v].end()) {
                adj[v].push_back(u);
            }
        }
    }

    int bandau = demPhanTu();
    int sauGoCanh = demPhanTu(x, y);
    int sauGoNut = demPhanTu(-1, -1, z);

    fo << (sauGoCanh > bandau ? "canh cau" : "khong la canh cau") << endl;
    fo << (sauGoNut > bandau ? "dinh khop" : "khong la dinh khop") << endl;

    fi.close();
    fo.close();
    return 0;
}