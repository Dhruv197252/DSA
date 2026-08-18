class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=-1;
        unordered_map<int,int>count;
        for(int i =0;i<=n-k;i++){
            for(int j=i;j<i+k;j++){
                int x=nums[j];

                bool present=false;
                for(int p = i;p<j;p++){
                    if(nums[p]==x){
                        present=true;
                        break;
                    }
                }
                if(!present){
                    count[x]++;
                }
            }
        }
        for(auto it:count){
            if(it.second==1){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};