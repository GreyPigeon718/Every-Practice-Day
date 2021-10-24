//括号字符串的有效性
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> S;
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == '(')
            S.push(c);
        else if (c == ')')
        {
            if (!S.empty() && S.top() == '(')
                S.pop();
            else {
                puts("NO");
                return 0;
            }
        }
        else {
            puts("NO");
            return 0;
        }
    }
    if (S.empty())
        puts("YES");
    else
        puts("NO");
    return 0;
}