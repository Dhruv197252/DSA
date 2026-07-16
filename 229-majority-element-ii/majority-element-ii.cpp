class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max1 = NULL;
        int count1 = 0;
        int max2 = NULL;
        int count2 = 0;

        for (int i = 0; i < n; i++) {
            if (max1 == nums[i]) {
                count1++;
            } else if (max2 == nums[i]) {
                count2++;
            } else if (count1 == 0) {
                max1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                max2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;

        for (int& num : nums) {
            if (num == max1) {
                freq1++;
            } else if (num == max2) {
                freq2++;
            }
        }
        if (freq1 > (n / 3)) {
            result.push_back(max1);
        }
        if (freq2 > (n / 3)) {
            result.push_back(max2);
        }
        return result;
    }
};