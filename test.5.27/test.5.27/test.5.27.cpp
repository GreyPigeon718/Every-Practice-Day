//> µ•¥ æ‡¿Î
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int endindex1 = -1, endindex2 = -1;

        int distance = INT_MAX;
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i] == word1)
                endindex1 = i;
            else if (words[i] == word2)
                endindex2 = i;
            if (endindex1 >= 0 && endindex2 >= 0)
                distance = min(distance, abs(endindex1 - endindex2));
        }
        return distance;
    }
};