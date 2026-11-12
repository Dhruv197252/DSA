class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count1 = 1;
        int count2 = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count1++;
            } else {
                count1 = 1;
            }
            if (nums[i] < nums[i - 1]) {
                count2++;
            } else {
                count2 = 1;
            }
            result = max(result, max(count1, count2));
        }
        return result;
    }
};