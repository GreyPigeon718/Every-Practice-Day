//> 取近似值
#include <iostream>
using namespace std;

int main()
{
    double x;
    cin >> x;
    int y = (int)(x + 0.5);
    cout << y << endl;
}

//> 合并表记录
#include<iostream>
#include<map>
using namespace std;

int main()
{
    int x;
    cin >> x;
    map<int, int>mp;
    for (int i = 0; i < x; ++i)
    {
        int key;
        int val;
        cin >> key >> val;
        if (mp.count(key))
            mp[key] += val;
        else
            mp[key] = val;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it)
        cout << it->first << ' ' << it->second << endl;
}



//> 提取不重复的整数
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    unordered_set<char> st;
    string res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (st.count(s[i]) != 1)
        {
            res += s[i];
            st.insert(s[i]);
        }
    }
    cout << res << endl;
    return 0;
}