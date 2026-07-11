class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
        for (int i = 0; i < chars.length(); i++) {
            charCount[chars[i] - 'a']++;
        }
        int result = 0;

        for (int i = 0; i < words.size(); i++) {
            vector<int> wordCount(26, 0);
            string word = words[i];

            for (int j = 0; j < word.length(); j++) {
                wordCount[word[j] - 'a']++;
            }

            bool possible = true;
            for (int k = 0; k < 26; k++) {
                if (charCount[k] < wordCount[k]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                    result += word.length();
                }
            
        }
        return result;
    }
};