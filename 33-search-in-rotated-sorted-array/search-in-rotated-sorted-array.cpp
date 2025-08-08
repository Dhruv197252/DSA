class Solution {
public:
    int searchRotated(vector<int>& nums, int si, int ei, int target) {
        if (si > ei) {
            return -1;
        }
        int mid = si + (ei - si) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[si] <= nums[mid]) { // Line 1
            if (nums[si] <= target && target <= nums[mid]) {
                return searchRotated(nums, si, mid - 1, target);
            } else {
                return searchRotated(nums, mid + 1, ei, target);
            }
        } else {
            if (nums[mid] <= target && target <= nums[ei]) {
                return searchRotated(nums, mid + 1, ei, target);
            } else {
                return searchRotated(nums, si, mid - 1, target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return searchRotated(nums, 0, nums.size() - 1, target);
    }
};