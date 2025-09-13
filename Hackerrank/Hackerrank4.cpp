#include <iostream>
using namespace std;

int demSo0(long long N) {
    long long count = 0;
    for (long long i = 5; N / i > 0; i *= 5) {
        count += N / i;
    }
    return count;
}

int main() {
    long long N;
    while (cin >> N) {
        cout << demSo0(N) << endl;
    }
    return 0;
}

