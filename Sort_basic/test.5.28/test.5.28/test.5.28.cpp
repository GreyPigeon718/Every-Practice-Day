//#include <iostream>
//
//using namespace std;
////class A {
////public:
////	A()
////	{
////		cout << "����" << endl;
////	}
////	~A()
////	{
////		cout << "����" << endl;
////	}
////};
//int main()
//{
//	int a; float b, c;
//	scanf_s("%2d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f\n", a, b, c);
//	/*class A* p = new class A[5];
//	delete p;*/
//	/*class A {
//	public:
//		void test(float a) { cout << '1' << endl; }
//	};
//	class B :public A
//	{
//	public:
//		void test(int b) { cout << '2' << endl; }
//	};
//	A *a = new A;
//	B *b = new B;
//	a = b;
//	b->test(1.1);*/
//}
//#include<iostream>
//using namespace std;
//class B0//����BO����
//{
//public://�ⲿ�ӿ�
//    virtual void display()//���Ա����
//    {
//        cout << "B0::display0" << endl;
//    }
//};
//class B1 :public B0//��������
//{
//public:
//    void display() { cout << "B1::display0" << endl; }
//};
//class D1 : public B1//��������
//{
//public:
//    void display() { cout << "D1::display0" << endl; }
//};
//void fun(B0 ptr)//��ͨ����
//{
//    ptr.display();
//}
//int main()//������
//{
//    B0 b0;//������������ָ��
//    B1 b1;//�������������
//    D1 d1;//�������������
//    fun(b0);//���û���B0������Ա
//    fun(b1);//����������B1������Ա
//    fun(d1);//����������D1������Ա
//}
//#include<iostream>
//using namespace std;
//class person {
//public:
//    virtual void buy_tickets() {
//        cout << "��ȫ��Ʊ" << endl;
//    }
//protected:
//    string _name;
//};
//class student :public person {
//public:
//     void  buy_tickets() {
//        cout << "����Ʊ" << endl;
//    }
//protected:
//    int _num;
//};
//void test(person k) {
//    k.buy_tickets();
//}
//int main() {
//    int n[][3] = { 10,20,30,40,50,60 };
//    int(*p)[3];
//    p = n;
//    cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
    /*person p;
    student s;
    test(p);
    test(s);
    system("pause");
    return 0;*/
//}
//��������
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; ++j)
    {
        cin >> v[j];
    }
    int head = v[0];
    int max = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = max >= 0 ? max + v[i] : v[i];
        head = std::max(head, sum);
        //if (max >= 0)
        //    sum = max + v[i];
        //else
        //{
        //    sum = v[i];
        //}
        //if (sum > head)
        //{
        //    head = sum;
        //}
        //if (sum < 0)
        //    sum = 0;
        max = sum;
    }
    cout << head << endl;
}