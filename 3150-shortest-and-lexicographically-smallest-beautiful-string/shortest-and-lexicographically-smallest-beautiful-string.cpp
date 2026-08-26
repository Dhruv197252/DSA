class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        for (int len = k; len <= n; len++) {
            string result = "";
            for (int start = 0; start <= n - len; start++) {
                string temp = s.substr(start, len);
                int ones = 0;
                for (int i = 0; i < temp.size(); i++) {
                    char ch = temp[i];

                    if (ch == '1') {
                        ones += 1;
                    }
                }
                if (ones == k) {
                    if (result.empty() || temp < result) {
                        result = temp;
                    }
                }
            }
            if (!result.empty()) {
                return result;
            }
        }
        return "";
    }
};