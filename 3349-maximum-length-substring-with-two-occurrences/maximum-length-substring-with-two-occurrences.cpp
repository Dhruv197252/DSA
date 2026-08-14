class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int start=0;
        int ans=0;
        unordered_map<char,int>frequency;

        for(int end=0;end<n;end++){
            char ch = s[end];
            frequency[ch]++;
            while(frequency[ch]>2){
                frequency[s[start]]--; 
                start++;
            }
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};