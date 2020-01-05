//
// Created by Jesson on 2019/12/5.
//

#include <ostream>
#include <iostream>
#include "数据类型回忆杀.h"

using namespace std;
#define WIDTH 5
#define HEIGHT 3

int jimmy[HEIGHT][WIDTH];
int n,m;
int shijisecond[100][365][24][60][60];
char str[] = "hello";

void increase(void* data,int type);
void printarray(int arg[],int length);

int main(){
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            jimmy[i][j] = (i+1)*(j+1);
            cout<<jimmy[i][j]<<",";
        }
        cout<<endl;
    }
    int arry[] = {1,2,3,4,56,7,89};
    printarray(arry,5);
    //测试void*
    char a = 12;
    short b = 9;
    long c = 299;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    increase(&c, sizeof(c));
    cout<<(int)a<<"  "<<b<<"  "<<c<<"  "<<endl;

    //==============动态内存的==============
    char input[100];
    int i,n;
    long* l;
    cout<<"input num:";
    cin.getline(input,100);
    i = atoi(input);
    l = new long[i];
    if(l==NULL)exit(1);
    for (int n = 0; n < i; ++n) {
        cout<<"enter number:";
        cin.getline(input,100);
        l[n] = atol(input);
    }
    cout<<"you entered :";
    for (int n = 0; n < i; ++n) {
        cout<<l[n]<<",";
    }
    delete[] l;
    return 0;
}
//数组传参
void printarray(int arg[],int length){
    for (int i = 0; i < length; ++i) {
        cout<<arg[i]<<" ";
    }
    cout<<"\n";
}
//void*
void increase(void* data,int type){
    switch(type){
        case sizeof(char):(*((char*)data))++;break;
        case sizeof(short):(*((short*)data))++;break;
        case sizeof(long):(*((long*)data))++;break;
    }
}
