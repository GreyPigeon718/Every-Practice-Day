#include <iostream>

using namespace std;

int main()
{
	int a = 1 - 2 + 1;
	size_t b = a;
	cout << b << endl;
}

//> 字符串最后一个单词的长度
#include<iostream>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        size_t pos = s.rfind(" ");
        cout << s.size() - pos - 1 << endl;
    }
}

//> 计算某字符出现次数
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char ch;
    cin >> ch;
    int count = 0;
    ch = tolower(ch);
    for (char c : s)
    {
        c = tolower(c);
        if (c == ch)
            count++;
    }
    cout << count;
    return 0;
}


//>  明明的随机数
#include<iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        st.emplace(x);
    }
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << endl;
    return 0;

}


//> 字符串分隔
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        // 补0
        int len = str.size();
        if (len % 8 != 0)
        {
            int count = 8 - len % 8;
            str.append(count, '0');
        }

        // 按格式输出
        int newLen = str.size();
        for (int i = 0; i < newLen; i += 8)
        {
            cout << str.substr(i, 8) << endl;
        }
    }
    return 0;
}



//> 进制转换
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    int size = s.size();
    for (int i = size - 1; i >= 2; --i)
    {
        int num = 0;
        if (s[i] >= 'A' && s[i] <= 'F')
            num = (10 + (s[i] - 'A')) * pow(16, size - i - 1);
        else
            num = (s[i] - '0') * pow(16, size - i - 1);
        sum += num;
    }
    cout << sum << endl;

}