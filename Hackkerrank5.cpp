#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    int nx, ny, nz;
    cin >> nx;
    unordered_set<int> x;
    for (int i = 0; i < nx; ++i) {
        int val;
        cin >> val;
        x.insert(val);
    }

    cin >> ny;
    unordered_set<int> y;
    for (int i = 0; i < ny; ++i) {
        int val;
        cin >> val;
        y.insert(val);
    }

    cin >> nz;
    unordered_set<int> z;
    for (int i = 0; i < nz; ++i) {
        int val;
        cin >> val;
        z.insert(val);
    }

    set<int> common;
    for (int val : x) {
        if (y.count(val) && z.count(val)) {
            common.insert(val);
        }
    }

    cout << common.size() << endl;
    for (int val : common) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}