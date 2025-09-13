
//Bài này là gộp của 2 bài trong phần map

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

void test1() {
    char s[] = "Hom nay thu hai. Hom sau thu ba, mot thu tu.";
    map<string, int> tanso; //map lưu tần số xuất hiện của các từ trong chuỗi s
    char *p = strtok(s," ,."); //p sẽ trỏ đến ký tự đầu tiên của từ đầu tiên trong chuỗi s quan hàm strtok
    while(p!=NULL) {
        string sub = string(p); 
        if(tanso.find(sub) == tanso.end())
            tanso[sub] = 1;
            else
            tanso[sub]++;
    
        p = strtok(NULL," ,.");// strtok trả về con trỏ đến ký tự đầu tiên của từ tiếp theo,
        }
    for(map<string,int>::iterator it = tanso.begin(); it!=tanso.end(); it++){ // duyệt các phần tử trong map tanso thông qua iterator it
        string key = it->first;//lấy key của phần tử hiện tại
        int val = it->second; 
        cout << "[" << key << "] xuat hien " << val << " lan." << endl;
    }
    tanso.erase(string("Hom"));
    map<string,int>::iterator jLeft = tanso.lower_bound("c"); //trả về vị trí phần tử đầu tiên có key không nhỏ hơn "c"
    map<string,int>::iterator jRight = tanso.upper_bound("s"); //trả về vị trí phần tử đầu tiên có key lớn hơn "s"
    vector<pair<string,int>> v(jLeft,jRight); //tạo vector v từ các phần tử trong map tanso từ jLeft đến jRight

    if (!tanso.empty())
        tanso.clear();
    
}

struct T {
    int x, y, z;
    T() { }
    T(int a,int b,int c):x(a),y(b),z(c){} 
    bool operator<(const T &t) const {
    if(x < t.x) return false;
    if(x == t.x && y < t.y) return false;
    if(x == t.x && y == t.y && z < t.z) return false;
    return true;
    }
};
    struct MyComp {
        bool operator()(const T& a,const T& b) const{
        if(a.x > b.x) return false;
        if(a.x == b.x && a.y > b.y) return false;
        if(a.x == b.x && a.y == b.y && a.z > b.z) return false;
        return true;
        }
    };  

int main() {

    test1();
    
    map<T,int> m1;
    m1[T(1,2,3)] = 1; m1[T(3,3,1)] = 2;
    m1[T(1,2,1)] = 3; m1[T(2,2,1)] = 4; 
    map<T,int, MyComp> m2(m1.begin(),m1.end());

    return 0;
}