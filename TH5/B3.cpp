#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <fstream>
#include <vector>

using namespace std;

#define FI "test2.inp"
#define FO "test2.out"

vector<vector<int>> adj;
int n, m;
int u, v, w;

void Floyd(vector<vector<int>> &adj)
{
    int v =adj.size();
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i <v; i++)
        {
            for (int j = 0; j <v; j++)
            {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

void readInput(ifstream &fi)
{
    fi >> n >> m;

    adj.assign(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
}

int main()
{
    ifstream fi(FI);
    ofstream fo{FO};

    readInput(fi);

    Floyd(adj);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}