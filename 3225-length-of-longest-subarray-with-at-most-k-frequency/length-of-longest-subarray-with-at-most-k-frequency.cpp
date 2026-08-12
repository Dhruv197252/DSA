class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start=-1;   
        unordered_map<int,int> frequency;
        int ans = 0;
        for(int end=0;end<n;end++){
            frequency[nums[end]]++;
            while(frequency[nums[end]]>k){
                start++;
                frequency[nums[start]]--;
            }
            ans =  max(ans,end-start);
        }
        return ans;
    }
};