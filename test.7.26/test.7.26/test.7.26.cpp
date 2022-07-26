#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v{ 1,3,2 };
	sort(v.begin(), v.end());
	sort(v.rbegin(), v.rend());
}
//> �ܳԼ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int nums, satiety;
        cin >> nums >> satiety;
        //> ͬʱ��סλ��
        vector<pair<int, int>> food(nums);
        for (int i = 0; i < nums; ++i)
        {
            int a;
            cin >> a;
            food[i] = { a,i + 1 };
        }
        sort(food.begin(), food.end(),
            [](pair<int, int> a, pair<int, int> b)
            {return a.first > b.first; });
        int sum = 0;
        int index = 0;
        //> ̰��
        while (sum < satiety && index < nums)
        {
            sum += food[index++].first;
        }
        if (sum >= satiety)
        {
            cout << index << endl;
            for (int i = 0; i < index; ++i)
            {
                cout << food[i].second << " ";
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}