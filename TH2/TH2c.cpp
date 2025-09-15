#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#define FI "DanhSachKe.INP"
#define FO "DanhSachKe.OUP"

int n;
vector<int> kq;
vector<vector<int>> a;

void test(ifstream &fi, ofstream &fo)
{
    fi >> n;
    fi.ignore(); 

    a.resize(n);
    kq.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(fi, line);
        stringstream ss(line);
        int x;
        while (ss >> x)
        {
            a[i].push_back(x);
            kq[i]++;
        }
    }

    fo << n << endl;
    for (int i = 0; i < n; i++)
    {
        fo << kq[i] << endl;
    }
}

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);
    if (!fi.is_open() || !fo.is_open())
    {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    test(fi, fo);
    return 0;
}