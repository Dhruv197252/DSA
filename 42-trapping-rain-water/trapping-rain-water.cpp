class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int left_max=0,right_max=0,sum=0;

        while(left<right){
            if(height[left]<height[right]){
                if(left_max>height[left]){
                    sum+=left_max-height[left];
                } else left_max=height[left];
                left++;
            } else {
                if(right_max>height[right]){
                    sum+=right_max-height[right];
                } else right_max=height[right];
                right--;
            }
        }
        return sum;
    }
};