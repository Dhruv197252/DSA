class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n =s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                st.pop();
            }
            ans = max(ans,int(st.size()));
        }
        return ans;
    }
};