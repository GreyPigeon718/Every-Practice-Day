//> ��Ծ��Ϸ II
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // ��ǰ������Զ�����±�
        int ans = 0;            // ��¼�ߵ������
        int nextDistance = 0;   // ��һ��������Զ�����±�
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // ������һ��������Զ�����±�
            if (i == curDistance) {                         // ������ǰ������Զ�����±�
                if (curDistance != nums.size() - 1) {       // �����ǰ������Զ�����±겻���յ�
                    ans++;                                  // ��Ҫ����һ��
                    curDistance = nextDistance;             // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                    if (nextDistance >= nums.size() - 1) break; // ��һ���ĸ��Ƿ�Χ�Ѿ����Դﵽ�յ㣬����ѭ��
                }
                else break;                               // ��ǰ������Զ�����±��Ǽ����յ㣬������ans++�����ˣ�ֱ�ӽ���
            }
        }
        return ans;
    }
};