//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//    void foo()
//    {
//        printf("1");
//    }
//    virtual void fun()
//    {
//        printf("2");
//    }
//};
//class B : public A
//{
//public:
//    void foo()
//    {
//        printf("3");
//    }
//    void fun()
//    {
//        printf("4");
//    }
//};
//int main(void)
//{
//    A a;
//    B b;
//    A* p = &a;
//    p->foo();
//    p->fun();
//    p = &b;
//    p->foo();
//    p->fun();
//    A* ptr = (A*)&b;
//    ptr->foo();
//    ptr->fun();
//    return 0;
//}
//class A
//{
//public:
//    virtual void func(int val = 1)
//    {
//        std::cout << "A->" << val << std::endl;
//    }
//    virtual void test()
//    {
//        func();
//    }
//};
//class B : public A
//{
//public:
//    void func(int val = 0)
//    {
//        std::cout << "B->" << val << std::endl;
//    }
//};
//int main(int argc, char* argv[])
//{
//    const int& a = 1;
//    B* p = new B;
//    p->test();
//    return 0;
//}
//最近公共祖先
//class LCA {
//public:
//    int getLCA(int a, int b) {
//        // write code here
//        while (a != b)
//        {
//            if (a > b)
//                a /= 2;
//            else
//                b /= 2;
//        }
//        return a;
//    }
//};
#include <iostream>

using namespace std;

int main()
{
    int x;
    int max = 0;
    cin >> x;
    int count = 0;
    while (x)
    {
        if (x & 1)
        {
            count++;
            max = max > count ? max : count;
        }
        else
            count = 0;
        x = x >> 1;
    }
    cout << max << endl;
    return 0;
}