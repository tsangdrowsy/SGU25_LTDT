#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<bool> appeared(N + 1, false); 
    bool HoanVi = true;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

       
        if (x < 1 || x > N || appeared[x]) {
            HoanVi = false;
        } else {
            appeared[x] = true;
        }
    }

    cout << (HoanVi ? "YES" : "NO") << endl;
    return 0;
}