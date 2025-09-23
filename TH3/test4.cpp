#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<queue>
#include<fstream>
using namespace std;

#define FI "test4.inp"
#define FO "test4.out"



const int MAXN = 1000000;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;

void bfs(int u) {
   queue<int> q;
   visited[u]=true;
   q.push(u);

   while (!q.empty())
   {
    int u = q.front(); q.pop();
    result.push_back(u);

    for (int v: adj[u])
    {
        if (!visited[v])
        {
            visited[v]=true;
            q.push(v);
        }
    }


   }
}

int main() {
    ifstream fi(FI);
    ofstream fo(FO);
    int n,x;

    fi >> n >> x;
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

    result.push_back(x); 
    bfs(x);

   
    result.erase(result.begin());

   
    sort(result.begin(), result.end());

    fo << result.size() << endl;
    for (int v : result) {
        fo << v << " ";
    }
    fo << endl;


    fi.close();
    fo.close();
    return 0;
}