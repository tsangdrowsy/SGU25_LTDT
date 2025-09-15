#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define FI "MATRANKE.INP"
#define FO "MATRANKE.OUT"

int n;
vector<vector<int>> a;
vector<int> deg;

void solve(ofstream& fo) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

 

 deg.resize(n);
    for (int j = 0; j < n; j++) {
        int degi = 0;
        for (int i = 0; i < n; i++) {
            degi += a[j][i];
        }
        deg[j] = degi;
    }

    fo << n << endl;
    for (int i = 0; i < n; i++) {
        fo << deg[i] << endl;
    }
}

  


int main() {
    freopen(FI, "r", stdin);    
    ofstream fo(FO);             

    if (!fo.is_open()) {
        cerr << "Không thể mở file output!" << endl;
        return 1;
    }
    solve(fo);                  
    fo.close();                 
    return 0;
}