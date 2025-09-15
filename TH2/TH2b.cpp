#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

#define FI "BacVaoBacRa.INP"
#define FO "BacVaoBacRa.OUT"

int n;
vector<vector<int>> a;
vector<int> hori;
vector<int> verti;


void solve(ofstream& fo) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

 verti.resize(n);
 hori.resize(n);


for (int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
hori[i]+=a[i][j];
verti[j]+=a[i][j];


    }
    fo << n << endl;
    for (int i = 0; i < n; i++) {
        fo << verti[i] << "  " << hori[i] << endl;
    }
}

int main (){

    freopen(FI, "r", stdin); 

    ofstream fo(FO);

     if (!fo.is_open()) {
        cerr << "Không thể mở file output!" << endl;
        return 1;
    }
    solve(fo);
    
    return 0;
}