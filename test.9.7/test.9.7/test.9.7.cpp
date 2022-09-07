// ”≈ ∆œ¥≈∆
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(), greater<int>());
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums2.size(); i++) {
            pairs.push_back({ i,nums2[i] });
        }
        sort(pairs.begin(), pairs.end(), [=](auto x, auto y) {return x.second > y.second; });


        int curr = 0, min = nums1.size() - 1, k = 0;
        vector<int> result(nums1.size(), 0);
        while (k != nums1.size()) {
            int ide = pairs[k].first, val = pairs[k].second;
            if (nums1[curr] > val) {
                result[ide] = nums1[curr];
                curr++;
                k++;
            }
            else {
                result[ide] = nums1[min];
                min--;
                k++;
            }
        }

        return result;
    }
};


class Solution1 {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(), greater<int>());
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums2.size(); i++) {
            pairs.push_back({ i,nums2[i] });
        }
        sort(pairs.begin(), pairs.end(), [=](auto x, auto y) {return x.second > y.second; });


        int curr = 0, min = nums1.size() - 1, k = 0;
        vector<int> result(nums1.size(), 0);
        while (k != nums1.size()) {
            int ide = pairs[k].first, val = pairs[k].second;
            if (nums1[curr] > val) {
                result[ide] = nums1[curr];
                curr++;
                k++;
            }
            else {
                result[ide] = nums1[min];
                min--;
                k++;
            }
        }

        return result;
    }
};
