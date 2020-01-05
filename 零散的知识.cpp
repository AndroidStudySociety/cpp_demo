//
// Created by Jesson on 2018-09-20.
//

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

//c++ 函数重载
int sum(int a,int b=0);
int sum(int a,int b, bool c=0);

int main(){

    cout<<"test cplus plus"<<endl;
    cout<<sum(1)<<endl;
    sum(1,2,-1); // 0 false 其他数值是true -1 true

    //演示auto的用法
    auto a = 30;
    static auto f = 0.1;
    auto p = new auto(5); //auto = int*
    const auto *q = &a,k=9;//auto =int
    //auto 不能用在函数参数中 注意 auto主要的作用还是在于简化代码
    std::map<double,int> map;
    auto it = map.begin();//这里可以少写很多的字符了


    return -1;
}


int sum(int a,int b){
    return a+b;
}

int sum(int a,int b, bool flag){
    if(flag){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    return a+b;
}