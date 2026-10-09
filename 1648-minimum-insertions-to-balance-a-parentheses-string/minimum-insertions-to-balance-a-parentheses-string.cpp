class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int count = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if(s[i]=='('){
                count++;
            }else{
                if(count>0){
                    count--;
                }else{
                    result++;
                }
                if(i<n && s[i+1]==')'){
                    i++;
                }else{
                    result++;
                }
            }
        }
        return result + count*2;
    }
};