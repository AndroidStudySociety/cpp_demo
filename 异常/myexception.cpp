//
// Created by Jesson on 2019/12/5.
//

#include "myexception.h"

using namespace std;
int main(){
    try {
        char* mystring;
        mystring = new char[10];
        if(mystring == NULL){
            throw "Allocation error";
        }
        for (int i = 0; i < 100; ++i) {
            if(i>10){
                throw new string; //改成throw；试一试看看触发了什么？
            }
            mystring[i] = 's';
        }
    }catch (int i){
        cout<<"Exception: ";
        cout<<" index "<<i<<" is out of range"<<endl;
    }catch (char* str){
        cout<<"exception"<<str<<endl;
    }catch (...){ //注意这里的最终捕获处理处理
        cout<<"all exception catched!!"<<endl;
    }

    try{
        throw myexception();
    }catch (myexception e){
        cout<<"myexception catched"<<endl;
        cout<<e.what()<<endl;
    }

    //terminating 触发terminat

    return -1;
}