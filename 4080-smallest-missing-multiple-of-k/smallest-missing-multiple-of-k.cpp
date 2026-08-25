class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        // unordered_map<int,int>mp;
        vector<int>multiple;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                // mp[nums[i]]++;
                multiple.push_back(nums[i]);
            }
        }
        int max=INT_MIN;
        // for(auto it: mp){
        //     if(it.first>max){
        //         max=it.first;
        //     }
        // }
        // max = max + k;
        // return max;
        // for(int i =0;i<multiple.size();i++){
        //     if(multiple[i]*k>max){
        //         max=multiple[i];
        //     }
        // }
        // max = max + k;
        // return max;
        int x=k;
        while(find(multiple.begin(),multiple.end(),x)!=multiple.end()){
            x= x+k;
        }
        return x;
    }
};