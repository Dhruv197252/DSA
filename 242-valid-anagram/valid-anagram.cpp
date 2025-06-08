class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            cout << "false";  //
            return false;
        }
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (count[t[i] - 'a'] == 0) {
                cout << "false";
                return false;
            }
            count[t[i] - 'a']--;
        }
        cout << "true";
        return true;
    }
    int main() {
        string s = "anagram";
        string t = "nagaram";
        isAnagram(s, t);

        return 0;
    }
};