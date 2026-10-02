class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        vector<string> temp;
        temp.push_back("(");

        while(!temp.empty()) {
            string s = temp.back();
            temp.pop_back();

            int open = 0;
            int close = 0;

            for(char ch : s) {
                if(ch == '(')
                    open++;
                else
                    close++;
            }

            if(s.size() == 2*n) {
                ans.push_back(s);
                continue;
            }

            if(open < n) {
                temp.push_back(s + "(");
            }

            if(close < open) {
                temp.push_back(s + ")");
            }
        }

        return ans;
    }
};