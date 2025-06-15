class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        vector<int> ans(2);

        
        for (int num : nums) {
            count[num]++;
        }

        
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                ans[0] = i; 
            } else if (count[i] == 0) {
                ans[1] = i; 
            }
        }

        return ans;
    }
};