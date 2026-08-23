class Solution {
public:
    bool calculate(string nums) {
        int mid = nums.size() / 2;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < mid; i++) {
            leftSum = leftSum + nums[i] - '0';
        }
        for (int i = mid; i < nums.size(); i++) {
            rightSum = rightSum + nums[i] - '0';
        }
        return leftSum == rightSum;
    }
    bool sumGame(string num) {
        bool found = false;
        int n = num.size();
        int rightQ = 0;
        int leftQ = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                found = true;
                if (i < n / 2) {
                    leftQ++;
                } else {
                    rightQ++;
                }
            }
        }
        if (found) {
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 0; i < n / 2; i++) {
                if (num[i] != '?') {
                    leftSum = leftSum + num[i] - '0';
                }
            }
            for (int i = n / 2; i < n; i++) {
                if (num[i] != '?') {
                    rightSum = rightSum + num[i] - '0';
                }
            }
            return 2 * (rightSum) + 9 * (rightQ) != 2 * (leftSum) + 9 * (leftQ);
        }

        return !calculate(num);
    }
};