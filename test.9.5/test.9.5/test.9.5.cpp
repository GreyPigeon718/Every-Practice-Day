#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int& g = d;
	a = 65;
	b = a++;
	c = ++b;
	d = c++;
	e = a, b, (c = c - b), ++d;
	f = e > d ? e : (++d);

	g = g << 16;
	char* s = (char*)&g;
	*s = f;
	*(s + 1) = e;
	cout << s;
}

// 乘积最大子数组
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		vector<int> maxN(nums), minN(nums);
		// maxN[i]: 它表示以第 i 个元素结尾的乘积最小子数组的乘积
		// minN[i]: 它表示以第 i 个元素结尾的乘积最大子数组的乘积
		for (int i = 1; i < size; ++i)
		{
			maxN[i] = max(maxN[i - 1] * nums[i], max(nums[i], minN[i - 1] * nums[i]));
			minN[i] = min(minN[i - 1] * nums[i], min(nums[i], maxN[i - 1] * nums[i]));
		}
		return *max_element(maxN.begin(), maxN.end());
	}
};


// 课程表
class Solution {
private:
    vector<vector<int>> edges; // 二维数组 建 图
    vector<int> visited; // 0表示未搜索过，1表示搜索中，2表示已完成
    bool valid = true; // 是否成环，成环就不能满足返回false

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            // 形成inof[0] -> info[1] , 就会保证 info[0] 在 info[1]前面
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};