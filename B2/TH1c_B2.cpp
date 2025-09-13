#include<iostream>
#include<queue>

using namespace std;

struct T{
    int x,y,z;
    T(int a,int b, int c):x(a),y(b),z(c){} //khai báo struct t có 3 biến x,y,z, hàm tạo T nhận 3 tham số a,b,c gán lần lượt cho x,y,z
};

bool operator <(const T&t1, const T &t2){ 
    return t1.z<t2.z; //gọi hàm bool operator < so sánh struct t1, t2 được gán tham chiếu và trả về true nếu t1.z < t2.z
}

bool operator >(const T&t1, const T &t2){
    return t1.z>t2.z; //ngược lại với hàm trên
}

//this is C++, not Java, đừng ghi hoa chữ đầu để gọi thư viện pls

struct MyComp{ 
    bool operator()(const T &t1, const T &t2) const{
        if(t1.x<t2.x) return true;
        return false;
    }
};

int main(){
    T a[]={T(4,4,3), T(2,2,5), T(1,5,4), T(3,3,6)};
    priority_queue<T> maxHeap(a,a+4); //tạo 1 maxHeap từ mảng a gồm 4 phần tử
    priority_queue<T, vector<T>, greater<T>> minHeap(a,a+4); //tạo 1 minHeap từ mảng a gồm 4 phần tử
    priority_queue<T, vector<T>, MyComp> myHeap(a,a+4); //tạo 1 myHeap từ mảng a gồm 4 phần tử
    while(!maxHeap.empty()){
        T t=maxHeap.top();maxHeap.pop(); 
        cout <<t.x<<" "<<t.y<<" "<<t.z<<endl; //lấy phần tử lớn nhất trong maxHeap, in ra x,y,z rồi xóa phần tử đó 
    }
    cout<<"\n\n";
    while (!minHeap.empty()){
        T t=minHeap.top(); minHeap.pop();
        cout <<t.x<<" "<<t.y<<" "<<t.z<<endl; //Ngược lại với trên
    }
    cout<<"\n\n";
    while(!myHeap.empty()){
        T t=myHeap.top(); myHeap.pop();
        cout <<t.x<<" "<<t.y<<" "<<t.z<<endl; // dưa trên struct MyComp để sắp xếp phần tử trong myHeap theo x tăng dần, in ra x,y,z rồi xóa phần tử đó
    }
      
    return 0;
}