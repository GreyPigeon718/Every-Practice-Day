//> 最小区间
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //> 使用multimap因为键值可以重复，对应的值也可重复，还可以排序
        //> multimap.first是num值，second是该num值所在的列值
        multimap<int, int> mmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (auto& num : nums[i])
            {
                mmp.insert(pair<int, int>(num, i));
            }
        }
        //> 以n个为间距进行相减 
        auto left = mmp.begin();
        auto right = mmp.begin();
        int mindste = INT_MAX;
        int len = mmp.size();
        //> remap第一列表示num，第二列表示第几个元素
        map<int, int> resmp;
        int resleft = 0, resright = 0;
        while (right != mmp.end())
        {
            //> 利用mmp.second来进行计算
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
                //> 如果没有left.second，则证明组完成，删除
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

//> 组合总和 II
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

//> 组合总和
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

//> 子集 II
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > startIndex && nums[i] == nums[i - 1]) { // 注意这里使用i > startIndex
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
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0);
        return result;
    }
};

//> 子集
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

//> 全排列 II
class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& used)
    {
        //> 说明找到一组了
        if (path.size() == nums.size())
        {
            vv.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
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
        //> 进行排序
        sort(nums.begin(), nums.end());
        //> used表示是否遍历过
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return vv;
    }
private:
    vector<vector<int>> vv;
    vector<int> path;
};


