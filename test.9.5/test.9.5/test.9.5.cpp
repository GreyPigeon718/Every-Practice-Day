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

// �˻����������
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		vector<int> maxN(nums), minN(nums);
		// maxN[i]: ����ʾ�Ե� i ��Ԫ�ؽ�β�ĳ˻���С������ĳ˻�
		// minN[i]: ����ʾ�Ե� i ��Ԫ�ؽ�β�ĳ˻����������ĳ˻�
		for (int i = 1; i < size; ++i)
		{
			maxN[i] = max(maxN[i - 1] * nums[i], max(nums[i], minN[i - 1] * nums[i]));
			minN[i] = min(minN[i - 1] * nums[i], min(nums[i], maxN[i - 1] * nums[i]));
		}
		return *max_element(maxN.begin(), maxN.end());
	}
};


// �γ̱�
class Solution {
private:
    vector<vector<int>> edges; // ��ά���� �� ͼ
    vector<int> visited; // 0��ʾδ��������1��ʾ�����У�2��ʾ�����
    bool valid = true; // �Ƿ�ɻ����ɻ��Ͳ������㷵��false

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
            // �γ�inof[0] -> info[1] , �ͻᱣ֤ info[0] �� info[1]ǰ��
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