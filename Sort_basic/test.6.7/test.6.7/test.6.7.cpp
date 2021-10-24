//ÌøÊ¯°å
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> v(n+1, 0);
	v[m] = 1;
	for (int i = m; i < n; ++i)
	{
		vector<int> vv;
		if (v[i] == 0)
			continue;
		for (int k = 2; k <= sqrt(i); k++)
		{
			if (i % k == 0)
			{
				vv.push_back(k);
				if (i / k != k)
					vv.push_back(i / k);
			}
		}
		for (int j = 0; j < vv.size(); ++j)
		{
			if ((vv[j] + i) <= n && v[vv[j] + i] != 0)
				v[vv[j] + i] = min(v[vv[j] + i], v[i] + 1);
			else if ((vv[j] + i) <= n)
				v[vv[j] + i] = v[i] + 1;
		}
	}
	if (v[n] == 0)
		cout << -1 << endl;
	else
		cout << v[n] - 1 << endl;
	return 0;
}