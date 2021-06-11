////#include <iostream>
//////#include <stdio.h>
////class A {
////public:
////    A() { p(); }
////    virtual void p() { printf("A"); }
////    virtual ~A() { p(); }
////};
////class B :public A {
////public:
////    B() { p(); }
////    void p() { printf("B"); }
////    ~B() { p(); }
////};
////int main(int, char**) {
////    A* a = new B();
////    delete a;
////}
////int main() {
////	long long a = 1, b = 2, c = 3;
////	printf("%d %d %d\n", a, b, c);
////	return 0;
////}
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int* p[] = { a,a + 1,a + 2,a + 3 }; 
//	int** q = p; 
//	cout << *(p[0] + 1) + **(q + 2) << endl;
//	cout << *(p[0] + 1) << endl;
//	//const char* p = "abc";
//	//const char* q = "abc123";
//	//while (*p = *q)
//	//	printf("%c %c", *p, *q);
//	char* ptr;
//	char myString[] = "abcdefg";
//	ptr = myString;
//	ptr += 5;
//	cout << *ptr << endl;
//
//}
//超长正整数相加
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string AddLongInteger(string x, string y)
{
    int size1 = x.size();
    int size2 = y.size();


    int size = size1 > size2 ? size1 : size2;


    vector<int> v1(size);
    vector<int> v2(size);


    for (int i = 0; i < size1; i++)
    {
        v1[i] = x[size1 - i - 1] - '0';
    }

    for (int i = 0; i < size2; i++)
    {
        v2[i] = y[size2 - i - 1] - '0';
    }


    vector<int> v(size + 1, 0);
    for (int i = 0; i < size; i++)
    {
        v[i] += v1[i] + v2[i];

        if (v[i] > 9)
        {
            v[i + 1] = v[i] / 10;
            v[i] %= 10;
        }
    }


    string s;

    if (v[size] == 0)
    {

        for (int i = 0; i < size; i++)
        {
            s.push_back(v[size - 1 - i] + '0');
        }
    }
    else
    {
        for (int i = 0; i < size + 1; i++)
        {
            s.push_back(v[size - i] + '0');
        }
    }

    return s;
}

int main()
{

    string x;
    string y;

    while (cin >> x >> y)
    {
        cout << AddLongInteger(x, y) << endl;
    }
    return 0;
}
//杨辉三角的变形
#include <iostream>
using namespace std;
int C(int n, int k)
{
    if (k == 1 || k == n * 2 - 1)
        return 1;
    if (k<1 || k>n * 2 - 1)
        return 0;
    else
        return C(n - 1, k - 2) + C(n - 1, k - 1) + C(n - 1, k);
}
int main()
{
    int N;
    cin >> N;
    for (int j = 1; j <= 2 * N - 1; j++)
    {
        if (C(N, j) % 2 == 0)
        {
            cout << j << endl;
            break;
        }
        else if (j == 2 * N - 1)
            cout << "-1" << endl;
    }
}