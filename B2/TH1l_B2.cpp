#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;

ifstream fin("tong.in");
#define cin fin

int main()
{
    char line[10001];
    int tong = 0;
    while(cin.getline(line,10000,'\n')){
        char *p;
        p = strtok(line," ");
        while(p!=NULL){
        int a;
        sscanf(p, "%d",&a);
        tong += a;
        p = strtok(NULL," ");
        }
    }
    cout<<tong<<endl;
    return 0;
}

//int test(){
   // char line[10001];
    //int tong = 0;
    //while(cin.getline(line,10000,'\n')){
        //int d = 0, a, tmp;
        //int len = strlen(line);
        //while(d<len){
            //sscanf(line+d,"%d%n",&a, &tmp);
            //tong += a;
            //d += tmp;
       // }
    //}
    //cout << tong << endl;
    //return 0;
//}