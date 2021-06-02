//#include <iostream>
//using namespace std;
//void func(const char** m) {
//    ++m;
//    cout << *m << endl;
//}
//int main() {
//    const char* a[] = { "morning", "afternoon", "evening" };
//    const char** p;
//    p = a;
//    func(p);
//    return 0;
//}
//#include <iostream>
//using namespace std;
//class Test {
//public:
//    int a;
//    int b;
//    virtual void fun() {}
//    Test(int temp1 = 0, int temp2 = 0)
//    {
//        a = temp1;
//        b = temp2;
//    }
//    int getA()
//    {
//        return a;
//    }
//    int getB()
//    {
//        return b;
//    }
//};
//
//int main()
//{
//    Test obj(5, 10);
//    // Changing a and b
//    int* pInt = (int*)&obj;
//    *(pInt + 0) = 100;
//    *(pInt + 1) = 200;
//    cout << "a = " << obj.getA() << endl;
//    cout << "b = " << obj.getB() << endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//class MyClass {
//public:
//    MyClass(int i = 0) { cout << 1; }
//    MyClass(const MyClass& x) { cout << 2; }
//    MyClass& operator=(const MyClass& x) { cout << 3; return*this; }
//    ~MyClass() { cout << 4; }
//};
//int main() {
//    MyClass obj1(1), obj2(2), obj3(obj1);
//    return 0;
//}
//#include <iostream>
//
//using namespace std;
//class cla {
//    static int n;
//public:
//    cla() { n++; }
//    ~cla() { n--; }
//    static int get_n() { return n; }
//};
//int cla::n = 0;
//int main()
//{
//    cla* p = new cla;
//    delete p;
//    cout << "n=" << cla::get_n() << endl;
//    return 0;
//}

//201301 java
#include <iostream>

using namespace std;

int func(int x, int y)
{
    if (x == 0 || y == 0)
        return 1;
    return func(x, y - 1) + func(x - 1, y);
}
int main()
{
    int m, n;
    cin >> m >> n;
    int ret = func(m, n);
    cout << ret << endl;
    return 0;
}