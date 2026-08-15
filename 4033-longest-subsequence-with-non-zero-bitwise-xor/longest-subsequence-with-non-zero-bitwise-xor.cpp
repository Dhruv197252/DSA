class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int result=0;
        bool allZero=true;

        for(int i=0;i<n;i++){
            int val = nums[i];
            result = result^val;
            if(val!=0){
                allZero=false;
            }
        }
        if(allZero){
            return 0;
        }
        if(result==0){
            return n-1;
        }else{
            return n;
        }
    }
};