//> ��״ͼ�����ľ���
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        // ����ջ��Ѱ�����С�ڵ�ǰλ�õľ��εĸ߶�
        stack<int> sk;
        // �����ң�������С�ڵ�ǰλ�þ��θ߶ȵ��±�
        for (int i = 0; i < n; ++i)
        {
            while (!sk.empty() && heights[sk.top()] >= heights[i])
            {
                sk.pop();
            }
            //> ջΪ�գ�˵����඼�ȵ�ǰ���θߣ���-1��ʾ
            left[i] = (sk.empty() ? -1 : sk.top());
            sk.push(i);
        }

        sk = stack<int>();
        // �����ң�������С�ڵ�ǰλ�þ��θ߶ȵ��±�
        for (int i = n - 1; i >= 0; --i)
        {
            while (!sk.empty() && heights[sk.top()] >= heights[i])
            {
                sk.pop();
            }
            //> ջΪ�գ�˵����඼�ȵ�ǰ���θߣ���n��ʾ
            right[i] = (sk.empty() ? n : sk.top());
            sk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};



//> ��ĸ��λ�ʷ���
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;

        for (auto& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            ump[key].emplace_back(str);
        }

        vector<vector<string>> res;
        for (auto it = ump.begin(); it != ump.end(); ++it)
            res.emplace_back(it->second);
        return res;
    }
};