//class Solution {
//public:
//    int cutOffTree(vector<vector<int>>& forest) {
//        // ������������С
//        m = forest.size(), n = forest[0].size();
//        // ��Ҫ������������
//        vector<pair<int, int>> trees;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                // ������ӵ����꼯����
//                if (forest[i][j] > 1) trees.push_back({ i, j });
//            }
//        }
//        // ���������������С������������ȷ������˳��
//        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
//            return forest[a.first][a.second] < forest[b.first][b.second];
//            });
//        // ��һ�εĳ���������[0, 0]
//        int x = 0, y = 0, ans = 0;
//        // ��������ʼ��ÿһ�ε���С����
//        for (int i = 0; i < trees.size(); ++i) {
//            // ʹ��bfs�㷨�ó���С����
//            int step = bfs(forest, x, y, trees[i].first, trees[i].second);
//            // ���һ�β��ɴ�򲻿��ܿ������е�����ֱ�ӷ���-1
//            if (step == -1) return -1;
//            // ������һ�εĳ������꣬��һ�εĳ������꼴��һ�ε�Ŀ������
//            x = trees[i].first;
//            y = trees[i].second;
//            // ���Ӳ���
//            ans += step;
//        }
//        return ans;
//    }
//private:
//    int bfs(vector<vector<int>>& forest, int x, int y, int tx, int ty) {
//        // ����һ�£������غ�Ŀ�ĵ���ͬ�����
//        if (x == tx && y == ty) return 0;
//        // bfs��׼ģ�棬��һ��������������
//        queue<pair<int, int>> q;
//        q.push({ x, y });
//        // ��һ��visit����������һ���㱻�ظ���
//        vector<vector<bool>> visit(m, vector<bool>(n, false));
//        // �ǵ��Ȱѵ�һ��������Ϊ�ѷ���
//        visit[x][y] = true;
//        int step = 0;
//        while (!q.empty()) {
//            // ���������б�push�����еĶ��൱�����ڵĵ�����һ��
//            ++step;
//            // ��ǰ�����е����е��step����ͬ�ģ����ǵ���һ����Ĳ���Ҳ����ͬ�ģ����һ����
//            int size = q.size();
//            for (int i = 0; i < size; ++i) {
//                int x = q.front().first, y = q.front().second;
//                q.pop();
//                for (int j = 0; j < 4; ++j) {
//                    int nx = x + dx[j];
//                    int ny = y + dy[j];
//                    // �߽紦��
//                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//                    // �����ظ���+��Ŀ��Ҫ��0�ǲ����ߵĵ㣩
//                    if (visit[nx][ny] || forest[nx][ny] == 0) continue;
//                    // �ҵ���Ŀ�����꣬���ز�������
//                    if (nx == tx && ny == ty) return step;
//                    // ���м�����һ����
//                    visit[nx][ny] = true;
//                    q.push({ nx, ny });
//                }
//            }
//        }
//        // �����ܷ��ʵĵ㶼�������˶�û�ܵ���Ŀ�����꣬�ͷ���-1
//        return -1;
//    }
//    const int dx[4] = { -1, 0, 1, 0 };
//    const int dy[4] = { 0, -1, 0, 1 };
//    int m, n;
//};

#include <iostream>

using namespace std;
class A { 
public: A(int a, int b) :_b(b), _a(_b) {} 
    void show() { cout << "a = " << this->_a << " b = " << this->_b << endl; } 
private: int _a; int _b; 
}; 
int main(void) { A a(3, 4); a.show(); return 0; }