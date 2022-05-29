//>  ��֤IP��ַ
class Solution {
public:
	/**
	* ��֤IP��ַ
	* @param IP string�ַ��� һ��IP��ַ�ַ���
	* @return string�ַ���
	*/
	string validIPAddress(string IP) {
		// write code here
		//�����˼·��ipv4����.������4�Σ�ֻ�������֣�����0+����Ϊ��ͷ
		//ipv6�ԣ���������8�Σ����������ֿ�������ĸ��ÿ�����4�����ֻ�������ĸ������0+������ͷ

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
	{//����pattern��str���зָ�
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
		{//�ж�ÿһ���ֶε���ֵ�ǲ���0-255
			string cur = ans[i];
			if (cur.empty() || (cur.size() > 1 && cur[0] == '0') || cur.size() > 3)
			{//����Ϊ�մ���ֱ�ӷ��� //ÿһ�ֶβ�����0Ϊ��ͷ
				return "Neither";
			}

			for (auto c : cur)
			{
				if (!isdigit(c))
				{//���粻�����֣�ֱ�ӷ���
					return "Neither";
				}
			}

			int temp = stoi(cur);
			if (temp < 0 || temp > 255)
			{//����Խ��
				return "Neither";
			}
		}

		//���û��.����������
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
		{//�ж�ÿһ���ֶε���ֵ�ǲ���0-255
			string cur = ans[i];
			if (cur.empty() || cur.size() > 4)
			{//����Ϊ�մ���ֱ�ӷ��� 
				return "Neither";
			}

			for (auto c : cur)
			{
				if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
				{//���粻�����֣�ֱ�ӷ���  //Ҳ����a-f��Ҳ����A-F
					return "Neither";
				}
			}

		}

		//���û��.����������
		return "IPv6";
	}

};
