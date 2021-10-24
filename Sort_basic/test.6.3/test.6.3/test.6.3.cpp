//#include <iostream>
//
//using namespace std;
//
//struct A {
//	void foo() { printf("foo"); }
//	virtual void bar() { printf("bar"); }
//	A() { bar(); }
//};
//struct B :A {
//	void foo() { printf("b_foo"); }
//	void bar() { printf("b_bar"); }
//};
//int main()
//{
//	int	**a[3][4];
//	cout << sizeof(*a[3][4]) << endl;
//	printf("%%%%%\n");
//	A* p = new B;
//	p->foo();
//	p->bar();
//	return 0;
//}
//¾®×ÖÆå
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Board {
//public:
//    bool checkWon(vector<vector<int> > board) {
//        // write code here
//        int H = board.size();
//        int L = board[0].size();
//        for (int i = 0; i < H; ++i)
//        {
//            if (board[i][0] + board[i][1] + board[i][2] == 3)
//                return true;
//        }
//        for (int j = 0; j < L; ++j)
//        {
//            if (board[0][L] + board[1][L] + board[2][L] == 3)
//                return true;
//        }
//        if (board[0][0] + board[1][1] + board[2][2] == 3 ||
//            board[0][2] + board[1][1] + board[2][0] == 3)
//            return true;
//        return false;
//    }
//};
//int main()
//{
//    return 0;
//}
//ÃÜÂëÇ¿¶È
#include <iostream>
#include <string>

using namespace std;

static int sorce = 0;

void String_Length(string s)
{
    if (s.size() <= 4)
        sorce += 5;
    else if (s.size() <= 7)
        sorce += 10;
    else
        sorce += 25;
}

void IsPla(string s)
{
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (islower(s[i]))
            a = 1;
        if (isupper(s[i]))
            b = 1;
    }
    if (a == 1 && b == 1)
        sorce += 20;
    else if (a == 1 || b == 1)
        sorce += 10;
    else
        sorce += 0;
}

void IsDigit(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
            count++;
    }
    if (count > 1)
        sorce += 20;
    else if (count == 1)
        sorce += 10;
    else
        sorce += 0;
}

void IsStr(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isalnum(s[i]));
        else
            count++;
    }
    if (count > 1)
        sorce += 25;
    else if (count = 1)
        sorce += 10;
    else
        sorce += 0;
}

void encourage(string s)
{
    int low = 0, up = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (islower(s[i]))
            low = 1;
        if (isupper(s[i]))
            up = 1;
        if (up + low = 2 && isdigit()

    }
}

int main()
{
    string passwd;
        cin >> passwd;
        String_Length(passwd);
        IsPla(passwd);
        IsDigit(passwd);
    IsStr(passwd);
    encourage(passwd);
}