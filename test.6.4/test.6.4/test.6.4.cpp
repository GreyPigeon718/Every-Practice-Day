//> 独特的电子邮件地址
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> emailSet;
        for (auto& email : emails) {
            string local;
            for (char c : email) {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            emailSet.emplace(local + email.substr(email.find('@')));
        }
        return emailSet.size();
    }
};