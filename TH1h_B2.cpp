#include <bitset>
#include <iostream>

using namespace std;

int main(){
        bitset<8> b1; //00000000
        bitset<8> b2("10110011"); // b2: 1 0 1 1 0 0 1 1 (MSB...LSB)
        bitset<8> b3(4); //00000100
        cout << "So bit 1 la " << (int)b2.count() << endl; // count trong bitset dùng để đếm số 1
        cout << "So bit 0 la " << (int)b2.size() - (int)b2.count() << endl; 
        b2.reset();
        b2.set(3);
        b2[0] = 1; b2[2] =1; 
        b1.set();
        b1.reset(2);
        b1.flip(); 
        b1.flip(1);
        cout << b1.any() << endl;
        cout << b1.none() << endl;
        cout << b1.test(3) << endl;
        cout << b1.to_string() << endl; // chuyển bitset sang chuỗi, khi in ra sẽ thấy bit bên trái là Bit lớn nhất, bên phải là Bit nhỏ nhất
        cout << b1.to_ulong() << endl; // chuyển bitset sang số nguyên không dấu long, còn to_ullong là long long
        
        return 0;
}
// trong ví dụ của thầy, thầy đã lật lại bit theo LSB ... MSB, mà thật ra trong bitset là MSB ... LSB

// gọi phép toán trên bitset and là &, or là |, xor là ^, not là ~

// ví dụ sử dụng: b4 = (b1 & b2) | (~b3 ^ b1);