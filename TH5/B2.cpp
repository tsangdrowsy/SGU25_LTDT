#include <iostream>
#include <queue>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

#define FI "test1.inp"
#define FO "test1.out"

const int MAXN = 1005;
vector<pair<int, int>> adj[MAXN];
int dist1[MAXN], dist2[MAXN], trace1[MAXN], trace2[MAXN];
bool visited[MAXN];
void dijkstra(int start, int n, int dist[], int trace[]) 
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        trace[i] = -1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        {
            visited[u] = true;
        }
        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                trace[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int n, m, s, t, x;
int u, v, w;

void readInput(ifstream &fi)
{
    fi >> n >> m >> s >> t >> x;

    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}

vector<int> tracePath(int start, int end, int trace[])
{
    vector<int> path;
    int current = end;
    while (current != -1)
    {
        path.push_back(current);
        current = trace[current];
    }
    reverse(path.begin(), path.end());
    return path;
}
 vector<int>path;

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);

    readInput(fi);

    dijkstra(s, n, dist1, trace1);
    dijkstra(x,n,dist2,trace2);

    vector<int> path1 = tracePath(s, x, trace1); // từ x đến z
    vector<int> path2 = tracePath(x, t, trace2); // từ z đến y

    path1.pop_back(); // xóa z khỏi path1 để tránh lặp
    vector<int> fullPath = path1;
    fullPath.insert(fullPath.end(), path2.begin(), path2.end());

    // vector<int>path;
    // int HTai=t;
    // while (HTai !=-1)
    // {
    //     path.push_back(HTai);
    //     HTai=trace[HTai];

    // }
    // if (!path[x])
    // {
    //     fo <<"Loi cu";
    //     return 0;
    // }

    // reverse(path.begin(), path.end());

    fo << fullPath.size() << "  " << dist1[x]+dist2[t] << endl;
    for (auto node : fullPath)
    {
        fo << node << "  ";
    }

    fo << endl;
    return 0;
}
