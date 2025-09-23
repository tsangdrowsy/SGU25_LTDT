#include<iostream>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;

const int MAXN=100000;
vector<int>adj[MAXN];
bool visited[MAXN];
vector<int>result;

void dfs_kodequy(int start)
{
    stack<int>st;
    st.push(start);

    while(!st.empty())
    {
        int u=st.top(); st.pop();
        if (!visited[u])
        {
            visited[u]=true;
            result.push_back(u);
            for (int v:adj[u])
            if (!visited[v])
            st.push(v);
            
        }
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    cin.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    dfs_kodequy(x);

    cout << result.size() << endl;
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

