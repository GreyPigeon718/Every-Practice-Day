//字符串计数
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    //根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
    string s1, s2;
    int len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2) {
        //只包含小写字母的字符串可以看成26进制的数制
        //将s1和s2补长到len2长度
        s1.append(len2 - s1.size(), 'a');
        s2.append(len2 - s2.size(), (char)('z' + 1));
        vector<int> array;
        for (int i = 0; i < len2; i++) {
            array.push_back(s2[i] - s1[i]);
        }
        int result = 0;
        for (int i = len1; i <= len2; i++) {
            for (int k = 0; k < i; k++) {
                result += array[k] * pow(26, i - 1 - k);
            }
        }
        //所有字符串最后都不包含是s2自身，所以最后要减1；
        cout << result - 1 << endl;
    }
    return 0;
}

//两个数组交集
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map <int, int> m;
        for (int num : nums1)
        {
            ++m[num];
        }
        vector<int> both;
        for (int num : nums2)
        {
            if (m.count(num))
            {
                both.push_back(num);
                --m[num];
                if (m[num] == 0)
                    m.erase(num);
            }
        }
        return both;
    }
};
//买卖股票最好的时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price : prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

