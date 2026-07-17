class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first=0;
        int second=0;
        int len=0;
        int n = s.size();
        vector<bool>count(256,0);

        while(second<n){
            while(count[s[second]]){
                
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            len=max(len,second-first+1);
            second++;
        }
        return len;
    }
};