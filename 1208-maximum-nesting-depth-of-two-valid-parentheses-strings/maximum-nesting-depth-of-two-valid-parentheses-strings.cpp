class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        int depth=0;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                depth++;
                if(depth%2==0){
                    result.push_back(0);
                }else{
                    result.push_back(1);
                }
            }else{
                if(depth%2==0){
                    result.push_back(0);
                }else{
                    result.push_back(1);
                }
                depth--;
            }
        }
        return result;
    }
};