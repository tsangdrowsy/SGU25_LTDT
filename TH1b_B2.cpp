#include <iostream>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int main(){

    //Làm ơn nhớ deque là double ended queue làm ơn TwT
    
    deque<pair<int,string>> a(2,make_pair<int,string>(-1,"NULL")); //code tạo 1 deque gồm 2 phần tử, mỗi phần tử là 1 pair<int,string> có giá trị (-1,"NULL")
    deque<pair<int,string>>b; //tạo 1 deque rỗng
    a.push_front(make_pair<int,string>(1,"Mot")); //thêm phần tử (1,"Mot") vào đầu deque a
    a.push_front(make_pair<int,string>(2, "Hai")); //thêm phần tử (2,"Hai") vào đầu deque a
    b=a; //gán deque b bằng deque a, khi đó b sẽ có 2 phần tử tạo sẵn và 2 phần tử được thêm vào 
    while(!b.empty()){
        pair<int,string>v=b.front(); //gán v = đầu deque b
        b.pop_front(); 
        cout<<"("<<v.first<<","<<v.second<<")"; //in ra v thứ nhất và v thứ hai(thật ra chỉ có 2 vì erm ... b chỉ có 2 phần tử được copy từ a)
    }
   
    cout<<"\n\nerm, it's running fine ig?";
    return 0;
}
