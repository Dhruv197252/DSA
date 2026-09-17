class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int>st;
        long number=0;
        long result=0;
        long sign=1;
        for(int i =0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10 + (s[i]-'0');
            }else if(s[i]=='+'){
                result = result+(number*sign);
                number=0;
                sign=1;
            }else if(s[i]=='-'){
                result = result+(number*sign);
                number=0;
                sign=-1;
            }else if(s[i]==')'){
                result=result+(number*sign);
                number=0;

                int stack_sign=st.top(); st.pop();
                int stack_result=st.top(); st.pop();

                result=result*stack_sign;
                result=result+stack_result;
            }else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
        }
        result=result+(number*sign);
        return result;
    }
};