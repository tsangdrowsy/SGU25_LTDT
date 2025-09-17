#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

#define FI "DanhSachCanh.INP"
#define FO "DanhSachCanh.OUT"

int main(){
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi.is_open() || !fo.is_open()){
        cerr<<"Khong mo duoc file";
        return 1;
    }

    int n, m;
    fi>>n>>m;

    vector<int>deg(n+1,0);
    
    for (int i=0;i<m;i++){
        int u,v;
        fi >> u>> v;
        deg[u]++;
        deg[v]++;

    }

    fo<<n<<endl;
    for(int i=1;i<=n;i++)
        fo<<deg[i]<<endl;

    fi.close();
    fo.close();
    return 0;
}