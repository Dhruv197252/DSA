class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<tuple<int, int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.emplace_back(
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            );
        }

        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) {
                 return get<1>(a) < get<1>(b);
             });

        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> indices(
            n + 1,
            vector<vector<int>>(5)
        );

        for (int i = 0; i < n; i++) {
            auto [l, r, weight, idx] = arr[i];

            int k = lower_bound(
                arr.begin(),
                arr.begin() + i,
                l,
                [](const tuple<int, int, int, int>& t, int val) {
                    return get<1>(t) < val;
                }
            ) - arr.begin();

            for (int j = 1; j < 5; j++) {
                long long skip = dp[i][j];
                long long take = dp[k][j - 1] + weight;

                if (skip > take) {
                    dp[i + 1][j] = skip;
                    indices[i + 1][j] = indices[i][j];
                } else {
                    vector<int> newIndex = indices[k][j - 1];
                    newIndex.push_back(idx);

                    sort(newIndex.begin(), newIndex.end());

                    if (skip == take && indices[i][j] < newIndex)
                        newIndex = indices[i][j];

                    dp[i + 1][j] = take;
                    indices[i + 1][j] = newIndex;
                }
            }
        }

        return indices[n][4];
    }
};