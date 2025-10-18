
#include <iostream>
#include <queue>
#include <climits>
#include <stack>
#include <fstream>
#include<math.h>
#include <algorithm>

using namespace std;

#define FI "test.inp"
#define FO "test.out"

struct Circle{
    int x,y,r;
};

const int MAXN = 1005;
vector<pair<int,int>> adj[MAXN];
int dist[MAXN], trace[MAXN], nhay[MAXN];
bool visited[MAXN];

int N, S, T;

Circle circles[MAXN];

double khoangcach(int i, int j) {
    double dx = circles[i].x - circles[j].x;
    double dy = circles[i].y - circles[j].y;
    return sqrt(dx * dx + dy * dy) - (circles[i].r + circles[j].r);
}

void buildGraph() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            double d = khoangcach(i, j);
            if (d <= 50) {
                adj[i].emplace_back(j, 0);
                adj[j].emplace_back(i, 0);
            } else if (d <= 60) {
                adj[i].emplace_back(j, 1);
                adj[j].emplace_back(i, 1);
            }
        }
    }
}

void dijkstra(int start) {
    for (int i = 1; i <= N; ++i) {
        dist[i] = INT_MAX;
        nhay[i] = INT_MAX;
        trace[i] = -1;
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dist[start] = 0;
    nhay[start] = 0;
    pq.emplace(0, 0, start); // (số lần nhảy, số hình tròn, start)

    while (!pq.empty()) {
        auto [jump, step, u] = pq.top(); pq.pop();

        if (jump > dist[u] || step > nhay[u]) continue;

        for (auto [v, cost] : adj[u]) {
            int nhayMoi = jump + cost;
            int buocMoi = step + 1;

            if (nhayMoi < dist[v] || (nhayMoi == dist[v] && buocMoi < nhay[v])) {
                dist[v] = nhayMoi;
                nhay[v] = buocMoi;
                trace[v] = u;
                pq.emplace(nhayMoi, buocMoi, v);
            }
        }
    }


}



int main()
{
    ifstream fi(FI);
    fi >> N >> S >> T;
    for (int i = 1; i <= N; ++i) {
        fi >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    buildGraph();
    dijkstra(S);

    if (dist[T] == INT_MAX) {
        cout << "0\n";
    } else {
        cout << "1\n";
        cout << dist[T] << " " << nhay[T] + 1 << "\n"; // +1 vì tính cả điểm đầu
        // printPath(T);
           vector<pair<int, int>> path;
    while (T != -1) {
        int prev = trace[T];
        int cost = -1;
        if (prev != -1) {
            for (auto [v, c] : adj[prev]) {
                if (v == T) {
                    cost = c;
                    break;
                }
            }
        }
        path.emplace_back(T, cost);
        T = prev;
    }

    reverse(path.begin(), path.end());
    for (auto [id, c] : path) {
        if (c != -1)
            cout << id << " " << c << "\n";
    }
    }

    return 0;
}



