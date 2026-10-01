class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.empty() || s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
                continue;
            }
            if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }
            if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
            if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};