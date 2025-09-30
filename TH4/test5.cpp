#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <algorithm>
#include<sstream>

using namespace std;

#define FI "test5.inp"
#define FO "test5.out"

vector<vector<int>> adj;
vector<int> degree;
vector<int> euler;
int n;


void readInput(ifstream &fi) {
    fi >> n;
    adj.assign(n + 1, vector<int>());
    degree.assign(n + 1, 0);

    string line;
    getline(fi, line); // bỏ dòng số lượng đỉnh

    for (int i = 1; i <= n; ++i) {
        getline(fi, line);
        istringstream iss(line);
        int u;
        iss >> u;
        int v;
        while (iss >> v) {
    adj[u].push_back(v);
    adj[v].push_back(u);        
    degree[u]++;
    degree[v]++;

        }
    }
}

// void readInput(ifstream &fi) {
//     fi >> n;
//     adj.assign(n + 1, vector<int>());
//     degree.assign(n + 1, 0);

//     for (int i = 1; i <= n; ++i)
//         for (int j = 1; j <= n; ++j) {
//             int x;
//             fi >> x;
//             for (int k = 0; k < x; ++k) {
//                 adj[i].push_back(j); //biến đổi sang danh sách kề
//                 degree[i]++;
//             }
//         }
// }

bool isEuler() {
    int oddCount = 0;
    for (int i = 1; i <= n; ++i)
    if (degree[i] % 2 != 0)
        oddCount++;

        return (oddCount == 0 || oddCount == 2);

}

void removeEdge(int u, int v) {
    auto it_u = find(adj[u].begin(), adj[u].end(), v);
    if (it_u != adj[u].end()) adj[u].erase(it_u);

    auto it_v = find(adj[v].begin(), adj[v].end(), u);
    if (it_v != adj[v].end()) adj[v].erase(it_v);
}

void findEulerCycle(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = adj[u].back();
            st.push(v);
            removeEdge(u, v);
        } else {
            euler.push_back(u);
            st.pop();
        }
    }
}

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi || !fo) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    readInput(fi);

    if (!isEuler()) {
        fo << 0 << endl;
    } else {
        fo << 1 << endl;
        int start = 1;
    for (int i = 1; i <= n; ++i) {
    if (degree[i] % 2 != 0) {
        start = i;
        break;
    }
}
    findEulerCycle(start);
        for (int i = euler.size() - 1; i >= 0; --i)
            fo << euler[i] << " ";
        fo << endl;
    }

    fi.close();
    fo.close();
    return 0;
}