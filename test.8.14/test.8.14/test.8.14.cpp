#include<iostream>
#include <math.h>
using namespace std;

void coupleNum(unsigned int n)
{
    for (unsigned i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            coupleNum(n / i);
            return;
        }
    }
    if (n - 1 > 0)
        cout << n << " ";
}

int main()
{
    unsigned int x;
    cin >> x;
    coupleNum(x);
    return 0;
}