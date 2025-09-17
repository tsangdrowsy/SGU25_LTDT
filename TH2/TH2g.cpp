#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

#define FI "TrungBinhCanh.INP"
#define FO "TrungBinhCanh.OUT"

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    int n;
    fi >> n;

    vector<vector<int>> w(n, vector<int>(n));
    int maxLen = 0;
    double total = 0;
    int count = 0;
    vector<pair<int, int>> canhDaiNhat;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fi >> w[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (w[i][j] > 0) {
                total += w[i][j];
                count++;
                if (w[i][j] > maxLen) {
                    maxLen = w[i][j];
                    canhDaiNhat.clear();
                    canhDaiNhat.emplace_back(i + 1, j + 1);
                } else if (w[i][j] == maxLen) {
                    canhDaiNhat.emplace_back(i + 1, j + 1);
                }
            }

    fo << canhDaiNhat.size() << endl;
    for (auto [u, v] : canhDaiNhat)
        fo << u << " " << v << " ";
    fo << endl;

    double avg = (count > 0) ? total / count : 0;
    fo << fixed << setprecision(2) << avg << endl;

    fi.close();
    fo.close();
    return 0;
}