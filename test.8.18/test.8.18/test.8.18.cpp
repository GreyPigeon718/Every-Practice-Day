#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> st;
    for (char ch : s)
    {
        if (st.count(ch) != 1)
            st.emplace(ch);
    }
    cout << st.size() << endl;
    return 0;
}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    cin >> x;
    string s = to_string(x);
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    string str;
    vector<string> vec;
    while (cin >> str) vec.push_back(str);
    sort(vec.begin(), vec.end());
    for (string s : vec) cout << s << endl;
    return 0;
}



#include<bitset>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n)
    {
        count++;
        n &= (n - 1);
    }
    cout << count << endl;
    return 0;
}