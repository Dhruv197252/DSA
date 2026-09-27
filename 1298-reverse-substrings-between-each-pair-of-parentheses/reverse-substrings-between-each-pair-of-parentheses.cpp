class Solution {
public:

    string solve(string s, int &i) {

        string result = "";

        while(i < s.length()) {

            if(s[i] == '(') {
                i++;

                string temp = solve(s, i);

                reverse(temp.begin(), temp.end());

                result += temp;
            }

            else if(s[i] == ')') {
                i++;
                return result;
            }

            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }

    string reverseParentheses(string s) {

        int i = 0;

        return solve(s, i);
    }
};