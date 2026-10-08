class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count=0;
        string answer="";
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                answer.push_back(s[i]);
                count++;
            }else{
                answer.push_back(s[i]);
                count--;
            }
            if(count==0){
                result= result+answer.substr(1, answer.size()-2);
                answer="";
            }
        }
        return result;
    }
};