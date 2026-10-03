class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        open=0
        close=0
        result=0
        for i in range(n):
            if(s[i]=='('):
                open=open+1
            else:
                close=close+1
            if(open==close):
                result=max(result, open+close)
            elif(close>open):
                open=0
                close=0
        open=0
        close=0
        for i in reversed(range(n)):
            if(s[i]==')'):
                close=close+1
            else:
                open=open+1
            if(open==close):
                result=max(result, open+close)
            elif(open>close):
                open=0
                close=0
        return result