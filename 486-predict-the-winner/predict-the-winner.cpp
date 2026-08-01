class Solution {
public:

    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int take_i = nums[i] + min(
            solve(i + 2, j, nums, dp),
            solve(i + 1, j - 1, nums, dp)
        );

        int take_j = nums[j] + min(
            solve(i, j - 2, nums, dp),
            solve(i + 1, j - 1, nums, dp)
        );

        return dp[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int total_score = accumulate(nums.begin(), nums.end(), 0);

        int p1_score = solve(0, n - 1, nums, dp);

        int p2_score = total_score - p1_score;

        return p1_score >= p2_score;
    }
};