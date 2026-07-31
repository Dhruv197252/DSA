class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;

        unordered_map<char, int> mp;
        for (int i = 0; i < word.size(); i++) {
            mp[word[i]]++;
        }
        vector<pair<char, int>> v;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            v.push_back(*it);
        }
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });

        int n = word.size();
        for (int i =0; i<v.size();i++){
            pushes = pushes + v[i].second*((i/8)+1);
        }
        return pushes;
    }
};