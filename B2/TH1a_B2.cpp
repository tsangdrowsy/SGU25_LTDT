#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main()
{
    vector<int>a;
    vector<int>b(100);
    vector<int>c(100,0); //là tạo mảng 100 ô, gán từng ô là 0
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.pop_back(); 
    for(int i = 0; i<a.size(); i++){
        int x=a[i]; //gán x bằng phần tử thứ i trong mảng a
        for(vector<int>::iterator it = a.begin(); it!=a.end();it++)
            int x=*it;
        for(vector<int>::reverse_iterator it=a.rbegin(); it!=a.rend();it++)
            int x=*it;
    }
    a.insert(find(a.begin(),a.end(),1),2);
    a.erase(find(a.begin(), a.end(), 3));
    if(!a.empty()){
        a.clear();
    }
    cout<<a.size()<<b.size()<<c.size();
    return 0;


}