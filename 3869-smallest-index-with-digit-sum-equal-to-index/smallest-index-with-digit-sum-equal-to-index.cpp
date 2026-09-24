class Solution {
public:
    int sum(int n){
        long sum=0;
        while(n){
            int a=n%10; 
            sum=sum+a;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n= nums.size();
        int ans=-1;

        for(int i=0;i<n;i++){
            if(sum(nums[i])==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};