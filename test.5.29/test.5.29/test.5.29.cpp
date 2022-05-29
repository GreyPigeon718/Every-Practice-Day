//>  验证IP地址
class Solution {
public:
	/**
	* 验证IP地址
	* @param IP string字符串 一个IP地址字符串
	* @return string字符串
	*/
	string validIPAddress(string IP) {
		// write code here
		//捋清楚思路：ipv4是以.隔开共4段，只能是数字，不以0+其他为开头
		//ipv6以：隔开，共8段，可以是数字可以是字母，每段最多4个数字或者是字母，可以0+其他开头

		if (IP.find(".") != string::npos)
		{
			return judgeIPV4(IP);
		}
		else if (IP.find(":") != string::npos)
		{
			return judgeIPV6(IP);
		}
		else
		{
			return "Neither";
		}
	}

	vector<string> split(const string& str, const string& pattern)
	{//根据pattern对str进行分割
		vector<string> result;
		string cur = str;
		int pos = str.find(pattern);
		while (pos != string::npos)
		{
			string tmp = cur.substr(0, pos);
			result.push_back(tmp);
			cur = cur.substr(pos + 1, str.size());
			pos = cur.find(pattern);
		}

		result.push_back(cur);
		return result;
	}

	string judgeIPV4(string& IP)
	{
		vector<string> ans = split(IP, ".");
		if (ans.size() != 4)
		{
			return "Neither";
		}

		for (int i = 0; i < ans.size(); i++)
		{//判断每一个分段的数值是不是0-255
			string cur = ans[i];
			if (cur.empty() || (cur.size() > 1 && cur[0] == '0') || cur.size() > 3)
			{//假如为空串，直接返回 //每一分段不能以0为开头
				return "Neither";
			}

			for (auto c : cur)
			{
				if (!isdigit(c))
				{//假如不是数字，直接返回
					return "Neither";
				}
			}

			int temp = stoi(cur);
			if (temp < 0 || temp > 255)
			{//假如越界
				return "Neither";
			}
		}

		//如果没有.就是其他的
		return "IPv4";
	}

	string judgeIPV6(string& IP)
	{

		vector<string> ans = split(IP, ":");
		if (ans.size() != 8)
		{
			return "Neither";
		}

		for (int i = 0; i < ans.size(); i++)
		{//判断每一个分段的数值是不是0-255
			string cur = ans[i];
			if (cur.empty() || cur.size() > 4)
			{//假如为空串，直接返回 
				return "Neither";
			}

			for (auto c : cur)
			{
				if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
				{//假如不是数字，直接返回  //也不是a-f，也不是A-F
					return "Neither";
				}
			}

		}

		//如果没有.就是其他的
		return "IPv6";
	}

};
