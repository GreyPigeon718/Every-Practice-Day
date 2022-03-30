//> 加油站
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < cost.size(); ++i)
        {
            cur += gas[i] - cost[i];
            res += gas[i] - cost[i];
            if (cur < 0)
            {
                start = i + 1;
                cur = 0;
            }
        }
        if (res < 0)
            return -1;
        return start;
    }
};
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int num = INT_MAX;
//         int res = 0;
//         for (int i = 0; i < cost.size(); ++i)
//         {
//             res += gas[i] - cost[i];
//             if (res < num)
//                 num = res;
//         }
//         if (res < 0)
//             return -1;
//         if (num >= 0)
//             return 0;
//         for (int i = cost.size() - 1; i >= 0; --i)
//         {
//             int rest = gas[i] - cost[i];
//             num += rest;
//             if (num >= 0)
//                 return i;
//         }
//         return -1;
//     }
// };
//class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         //> 暴力
//         for (int i = 0; i < cost.size(); ++i)
//         {
//             int rest = gas[i] - cost[i]; //> 
//             int index = (i + 1) % cost.size();
//             while (i != index && rest > 0) //> 模拟实现一圈
//             {
//                 rest += gas[index] - cost[index];
//                 index = (index + 1) % cost.size();
//             }
//             if (i == index && rest >= 0)
//                 return i;
//         }
//         return -1;
//     }
// };