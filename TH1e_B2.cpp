#include<iostream>
#include<string>

using namespace std;

int main(){
    string a = "acm icpc world";
    cout <<a.size()<<endl;
    cout <<!a.empty()<<endl; 
    a+= "final";
    a.push_back('.');
    cout <<a.find("icpm")<< " "<<endl;
    cout << (a.find("acm", 5) == string::npos) << " "<<endl;
    cout << a.find_first_of("ijk") << " "<<endl; //tìm vị trí đầu tiên của i,j,k
    cout << a.find_first_not_of("abcde") << " "<<endl; //tìm vị trí đầu tiên không phải là a,b,c,d,e
    cout << a.find_first_of(' ', 4) << " "<<endl; //
    string b = a.substr(4, 4); //tạo chuỗi b từ chuỗi a, bắt đầu từ vị trí 4, độ dài 4
    string c =a.substr(15);
    a.insert(a.size()-1, " 2010"); //chèn chuỗi " 2010" vào trước vị trí a.size()-1, a.size()-1 là vị trí của dấu chấm
    a.erase(14); // xoá từ vị trí 14 đến hết
    a.replace(9, a.size() -9, "WF"); //thay thế từ vị trí 9 đến hết bằng "WF"
    a.erase(3); //xoá từ vị trí sau số 3 đến hết
    printf("%s\n", a.c_str()); //in chuỗi a, a.c_str() chuyển chuỗi a về dạng mảng ký tự
    return 0;
}