//
// Created by Jesson on 2019/12/1.
//

#include "Cplusplusext.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int iabs(int a){
    return a>0?a:-a;
}

double fabs(double a){
    return a>0?a:-a;
}

//==============操作符重载
struct COMP{
    float real;
    float image;
};
COMP operator+(COMP one,COMP two){
    one.real += two.real;
    one.image += two.image;
    return one;
}





int main()
{
    //开始学习
    char name[30];
    int age;
    cout<<"pls input your name:"<<endl;
//    cin>>name;
//    cin>>age;
    cout<<"your name is: "<<name<<endl;
    cout<<"your age is: "<<age<<endl;

    //输出
    printf("%c\n%d\n%f\n",'1',100,200.00);
    printf("%5c\n%5d\n%6.3f\n",'1',100,200.00);
    //进制输出
    int i= 100;
    cout<<i<<endl;
    cout<<dec<<i<<endl;
    cout<<hex<<i<<endl;
    cout<<oct<<i<<endl;
    cout<<setbase(16)<<i<<endl;
    cout<<setw(10)<<1123<<endl;
    cout<<setw(10)<<setfill('w')<<1123<<endl;
    cout<<setw(10)<<setfill('w')<<setiosflags(ios::right)<<1123<<endl;

    //测试运算符重载
    COMP one = {1,2};
    COMP two = {100,200};
    COMP result = operator+(one,two);
    cout<<result.image<<"====="<< result.real<<endl;


    return 0;
}
