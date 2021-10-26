//下一个更大的元素
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.size());
        for (int i = 0; i < nums1.size(); ++i)
        {
            int j = 0;
            while (j < nums2.size() && nums2[j] != nums1[i])
                j++;
            int pos = j + 1;
            while (pos < nums2.size() && nums2[pos] <= nums2[j])
                pos++;
            v[i] = pos < nums2.size() ? nums2[pos] : -1;
        }
        return v;
    }
};