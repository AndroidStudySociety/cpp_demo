//
// Created by Jesson on 2019/12/27.
//

#include "autoptr.h"

#include <iostream>
#include <string>
#include <memory>
using namespace std;

#include <memory>
#include <iostream>
//class Test
//{
//public:
//    Test()
//    {
//        std::cout << "Test()" << std::endl;
//    }
//    ~Test()
//    {
//        std::cout << "~Test()" << std::endl;
//    }
//};
//int main()
//{
//    std::shared_ptr<Test> p1 = std::make_shared<Test>(); //分配内存了 new
//    std::cout << "1 ref:" << p1.use_count() << std::endl; //计算器的概念
//    {
//        std::shared_ptr<Test> p2 = p1;
//        std::cout << "2 ref:" << p1.use_count() << std::endl;
//    }
//    std::cout << "3 ref:" << p1.use_count() << std::endl;
//    return 0;
//}

//相互引用的问题的解决
class TestB;
class TestA
{
public:
    TestA()
    {
        std::cout << "TestA()" << std::endl;
    }
    void ReferTestB(std::shared_ptr<TestB> test_ptr)
    {
        m_TestB_Ptr = test_ptr;
    }
    ~TestA()
    {
        std::cout << "~TestA()" << std::endl;
    }
private:
    std::shared_ptr<TestB> m_TestB_Ptr; //TestB的智能指针
};
class TestB
{
public:
    TestB()
    {
        std::cout << "TestB()" << std::endl;
    }
    void ReferTestB(std::shared_ptr<TestA> test_ptr)
    {
        m_TestA_Ptr = test_ptr;
    }
    ~TestB()
    {
        std::cout << "~TestB()" << std::endl;
    }
    std::shared_ptr<TestA> m_TestA_Ptr; //TestA的智能指针
};
//int main()
//{
//    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
//    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
//    ptr_a->ReferTestB(ptr_b);
//    ptr_b->ReferTestB(ptr_a);
//    return 0;
//}

unique_ptr<int> clone(int p)
{
    unique_ptr<int> pInt(new int(p));
    return pInt;    // 返回unique_ptr
}

int main()
{
    std::unique_ptr<int> pInt;
    pInt.reset(new int());
    int *p = pInt.release(); //释放所有权
    //由于unique_ptr有std::unique_ptr<T[]>的重载函数，所以它可以用来管理数组资源
    std::unique_ptr<int[]> pArray(new int[3]{1,3,3});

    // 创建一个unique_ptr实例
    unique_ptr<int> pInt2(new int(5));//new 操作符创建int指针 传递给unique_ptr构造
    cout << *pInt2;
    //注意这里  unique_ptr没有copy构造函数，不支持普通的拷贝和赋值操作。
//    unique_ptr<int> pInt3(pInt);    // 报错
//    unique_ptr<int> pInt4 = pInt;   // 报错
    unique_ptr<int> pInt3 = std::move(pInt2); //转移指针的所有权
    //cout << *pInt2 << endl;//这里程序崩溃？ 因为pInt2 已经是空指针了，交出了所有权
    cout << pInt3.get() << endl;
    //unique_ptr不支持拷贝操作，但却有一个例外：可以从函数中返回一个unique_ptr。
    int pp = 500;
    unique_ptr<int> ret = clone(pp);
    cout << *ret << endl;
}


