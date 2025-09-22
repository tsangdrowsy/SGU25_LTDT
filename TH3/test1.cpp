#include <iostream>
#include <vector>
#include <sstream>
#include<queue>
#include <algorithm>
#include<fstream>
using namespace std;

#define FI "test1.inp"
#define FO "test1.out"


const int MAXN = 100000;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

void bfs(int start, int end) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                if (v == end) return; // dừng sớm nếu đã đến y
            }
        }
    }
}



int main(){
   int n, x, y;
    ifstream fi(FI);
    ofstream fo(FO);

    fi >> n >> x >> y;
    fi.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    bfs(x, y);

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
