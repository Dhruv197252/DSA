class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxleft = 0;
        int minleft = 0;
        int maxright = 0;
        int minright = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            maxleft++;
            if (nums[i] == maxi) {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            minleft++;
            if (nums[i] == mini) {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            maxright++;
            if (nums[i] == maxi) {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            minright++;
            if (nums[i] == mini) {
                break;
            }
        }

        int pos1 = maxleft + minright;
        int pos2 = maxright + minleft;
        int pos3 = max(maxright,minright);
        int pos4 = max(maxleft,minleft);
        return min({pos1, pos2, pos3, pos4});
    }
};