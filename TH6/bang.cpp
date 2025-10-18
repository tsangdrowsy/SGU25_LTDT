#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <fstream>
#include <climits>

using namespace std;

#define FI "test1.inp"
#define FO "test1.out"

const int MAXN = 105;
int N, M, xi, yi, xj, yj;
int A[MAXN][MAXN];
int cost[MAXN][MAXN];
pair<int, int> trace[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0}; // hướng đi: lên, xuống, trái, phải
int dy[] = {0, 0, -1, 1};

bool trongBang(int x, int y)
{
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

void dijkstra()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cost[i][j] = INT_MAX;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    cost[xi][yi] = 0;
    pq.emplace(0, xi, yi);

    while (!pq.empty())
    {
        auto [c, x, y] = pq.top();
        pq.pop();
        if (visited[x][y])
            continue;
        visited[x][y] = true;

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (trongBang(nx, ny) && A[nx][ny] != 0)
            {
                int newCost = c + ((nx == xj && ny == yj) ? 0 : A[nx][ny]);
                if (newCost < cost[nx][ny])
                {
                    cost[nx][ny] = newCost;
                    trace[nx][ny] = {x, y};
                    pq.emplace(newCost, nx, ny);
                }
            }
        }
    }
}



int main()
{
    ifstream fi(FI);

    fi >> N >> M >> xi >> yi >> xj >> yj;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            fi >> A[i][j];

    if (A[xi][yi] == 0 || A[xj][yj] == 0)
    {
        cout << "0\n";
        return 0;
    }

    dijkstra();

    if (cost[xj][yj] == INT_MAX)
    {
        cout << "0\n";
    }
    else
    {
        cout << "1\n";
        cout << cost[xj][yj] << "\n";
        // printPath();
        vector<pair<int, int>> path;
        int x = xj, y = yj;
        while (!(x == xi && y == yi))
        {
            path.emplace_back(x, y);
            tie(x, y) = trace[x][y];
        }
        path.emplace_back(xi, yi);
        reverse(path.begin(), path.end());
        for (auto [x, y] : path)
            cout << x << " " << y << "\n";
    }

    return 0;
}
