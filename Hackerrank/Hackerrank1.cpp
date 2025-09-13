#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string s;
        getline(cin, s);

        unordered_map<string, int> freq;
        int maxCount = 0;

        for (size_t i = 0; i + 2 < s.size(); ++i) {
            string triplet = s.substr(i, 3);
            freq[triplet]++;
            if (freq[triplet] > maxCount) {
                maxCount = freq[triplet];
            }
        }

        cout << maxCount << endl;
    }

    return 0;
}