#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

#define FI "test.inp"
#define FO "test.out"

vector<vector<int>> adj;
vector<int> degree;
vector<int> euler;
int n;

void readInput(ifstream &fi) {
    fi >> n;
    fi.ignore();
    adj.assign(n + 1, vector<int>(n + 1, 0));
    degree.assign(n + 1, 0); //khá tương tự với resize

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            fi >> adj[i][j];
            degree[i] += adj[i][j];
        }
}

bool isEuler() { //kiểm tra bậc chẵn
    for (int i = 1; i <= n; ++i)
        if (degree[i] % 2 != 0)
            return false; 
    return true;
}

void findEulerCycle(int start) { //hàm euler
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        bool found = false;
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v]) {
                st.push(v);
                adj[u][v]--;
                adj[v][u]--;
                found = true;
                break;
            }
        }
        if (!found) {
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
        findEulerCycle(1); // bắt đầu từ đỉnh 1
        for (int i = euler.size() - 1; i >= 0; --i)
            fo << euler[i] << " ";
        fo << endl;
    }

    fi.close();
    fo.close();
    return 0;
}