#include <iostream>
#include <queue>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

#define FI "test.inp"
#define FO "test.out"

const int MAXN = 1005;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN], trace[MAXN];
bool visited[MAXN];

void dijkstra(int start, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        trace[i] = -1;
    }

    dist[start]=0;

    for (int i = 1; i <= n; i++)
    {
        int u = -1;
        int minDist = INT_MAX;

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
    
        if (u == -1)break;

        visited[u] = true;

        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                trace[v] = u;
            }
        }
    }
}

// cài bằng priority_queue (nhanh hơn cho đồ thị lớn, nhưng không dò được phần tử âm)

// void dijkstra(int x, int n) // x là start
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = INT_MAX;
//         visited[i] = false;
//         trace[i] = -1;
//     }
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     dist[x] = 0;
//     pq.push({0, x});

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();

//         if (visited[u])
//             continue;
//         {
//             visited[u] = true;
//         }
//         for (auto &[v, w] : adj[u])
//         {
//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 trace[v] = u;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }

int n, m, x, y;
int u, v, w;

void readInput(ifstream &fi)
{
    fi >> n >> m >> x >> y;

    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u,w});
    }
}

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);

    readInput(fi);

    dijkstra(x, n);

    vector<int> path;
    int HTai = y;
    while (HTai != -1)
    {
        path.push_back(HTai);
        HTai = trace[HTai];
    }

    reverse(path.begin(), path.end());

    fo << path.size() << "  " << dist[y] << endl;
    for (auto node : path)
    {
        fo << node << "  ";
    }

    fo << endl;
    return 0;
}
