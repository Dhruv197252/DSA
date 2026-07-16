class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max = NULL;
        int count=0;
        for(int i =0;i<n;i++){
            if(count==0){
                max=nums[i];
                count++;
            }else if(max==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return max;
    }
};