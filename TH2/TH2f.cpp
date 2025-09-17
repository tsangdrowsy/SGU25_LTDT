#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "BonChua.INP"
#define FO "BonChua.OUT"

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    int n;
    fi >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<int> bonChua;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fi >> a[i][j];

    for (int i = 0; i < n; ++i) {
        bool coRa = false;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 0) {
                coRa = true;
                break;
            }
        }
        if (!coRa)
            bonChua.push_back(i + 1); 
    }

    // Ghi kết quả
    fo << bonChua.size() << endl;
    if (!bonChua.empty()) {
        for (int v : bonChua)
            fo << v << " ";
        fo << endl;
    }

    fi.close();
    fo.close();
    return 0;
}