class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        int m = logs.size();

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<pair<int, int>> timeIndex(q);

        for (int i = 0; i < q; i++) {
            timeIndex[i].first = queries[i];
            timeIndex[i].second = i;
        }

        sort(timeIndex.begin(), timeIndex.end());

        unordered_map<int, int> mp;

        vector<int> result(q);

        int i = 0;
        int j = 0;

        for (int k = 0; k < q; k++) {

            int curtime = timeIndex[k].first;
            int ind = timeIndex[k].second;

            int start = curtime - x;
            int end = curtime;

            while (j < m && logs[j][1] <= end) {
                int server = logs[j][0];
                mp[server]++;
                j++;
            }

            while (i < j && logs[i][1] < start) {
                int server = logs[i][0];
                mp[server]--;

                if (mp[server] == 0) {
                    mp.erase(server);
                }

                i++;
            }

            result[ind] = n - mp.size();
        }

        return result;
    }
};