class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int n = s.length();
        int score = 0;
        int depth = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                st.push(s[i]);
                depth++;
            }
            else {
                st.pop();
                depth--;

                if(s[i-1] == '(') {
                    score = score + pow(2, depth);
                }
            }
        }

        return score;
    }
};