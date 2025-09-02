class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, mask = 0;
        int last[128] = {0};
        for (int i = 0, j = 0, n = s.length(); j < n; ++j) {
            int ch = s[j];
            i = max(i , last[ch]);
            res = max(res , j - i + 1);
            last[ch] = j + 1;
        }
        return res;
    }
};