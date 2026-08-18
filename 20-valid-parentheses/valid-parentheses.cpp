class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i =0;i<n;i++){
            char ch = s[i];
            if(st.empty() || ch=='('|| ch=='{'|| ch=='['){
                st.push(ch);
                continue;
            }
            if(ch==')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(ch=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};