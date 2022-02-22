//> ��С����
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //> ʹ��multimap��Ϊ��ֵ�����ظ�����Ӧ��ֵҲ���ظ�������������
        //> multimap.first��numֵ��second�Ǹ�numֵ���ڵ���ֵ
        multimap<int, int> mmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (auto& num : nums[i])
            {
                mmp.insert(pair<int, int>(num, i));
            }
        }
        //> ��n��Ϊ��������� 
        auto left = mmp.begin();
        auto right = mmp.begin();
        int mindste = INT_MAX;
        int len = mmp.size();
        //> remap��һ�б�ʾnum���ڶ��б�ʾ�ڼ���Ԫ��
        map<int, int> resmp;
        int resleft = 0, resright = 0;
        while (right != mmp.end())
        {
            //> ����mmp.second�����м���
            resmp[right->second]++;
            while (resmp.size() == n)
            {
                if (right->first - left->first < mindste)
                {
                    mindste = right->first - left->first;
                    resleft = left->first;
                    resright = right->first;
                }
                resmp[left->second]--;
                //> ���û��left.second����֤������ɣ�ɾ��
                if (resmp[left->second] == 0)
                {
                    resmp.erase(left->second);
                }
                left++;
            }
            right++;
        }
        return { resleft,resright };
    }
};

//> ����ܺ� II
class Solution {
public:
    void backtracking(vector<int>& candidates, vector<bool>used, int target, int sum, int startindex)
    {
        if (sum == target)
        {
            vv.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; ++i)
        {
            if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false)
                continue;
            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, used, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, used, target, 0, 0);
        return vv;
    }
private:
    vector<vector<int>> vv;
    vector<int> path;
};

//> ����ܺ�
class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int sum, int startindex)
    {
        if (sum > target) {
            return;
        }
        if (sum == target)
        {
            vv.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size(); ++i)
        {
            if (i < 0 && i > candidates.size() && candidates[i] + sum > target)
                return;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return vv;
    }
private:
    vector<vector<int>> vv;
    vector<int> path;
};

//> �Ӽ� II
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // ������Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > startIndex && nums[i] == nums[i - 1]) { // ע������ʹ��i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ȥ����Ҫ����
        backtracking(nums, 0);
        return result;
    }
};

//> �Ӽ�
class Solution {
public:
    void backtracking(vector<int>& nums, int StartIndex)
    {
        vv.push_back(path);
        if (StartIndex >= nums.size())
            return;
        for (int i = StartIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        backtracking(nums, 0);
        return vv;
    }
private:
    vector<vector<int>> vv;
    vector<int> path;
};

//> ȫ���� II
class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& used)
    {
        //> ˵���ҵ�һ����
        if (path.size() == nums.size())
        {
            vv.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            // used[i - 1] == true��˵��ͬһ��֧nums[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
            // ���ͬһ����nums[i - 1]ʹ�ù���ֱ������
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if (used[i] == false)
            {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //> ��������
        sort(nums.begin(), nums.end());
        //> used��ʾ�Ƿ������
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return vv;
    }
private:
    vector<vector<int>> vv;
    vector<int> path;
};


