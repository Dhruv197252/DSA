class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int j = m-1;

        // go for suffix
        vector<int> indices;
        vector<int> suffix(n+1,0);

        for(int i =n-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                j--;
            }
            suffix[i]=m-1-j;
        }

        int changed=0;
        j=0;

        for(int i =0;i<n && j<m;i++){
            if(word1[i]==word2[j]){
                indices.push_back(i);
                j++;
            }else if(changed==0){
                int remaining = m-1-j;
                if(suffix[i+1]>=remaining){
                    indices.push_back(i);
                    changed=1;
                    j++;
                }
            }
        }
        if(j==m){
            return indices;
        }
        return {};
    }
};