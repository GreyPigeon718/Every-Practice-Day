//Î¢ÐÅºì°ü
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int ans = gifts[n / 2];
        int num = 0;
        for (int i = 0; i < gifts.size(); i++) {
            if (gifts[i] == ans) {
                num++;
            }
        }
        return num <= n / 2 ? 0 : ans;
    }
};