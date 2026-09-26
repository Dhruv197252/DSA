class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        int i=0;
        unordered_map<string,string>count;
        for(int j=0;j<knowledge.size();j++){
            count[knowledge[j][0]]=knowledge[j][1];
        }
        string result="";
        string temp;
        while(i<n){
            if(isalpha(s[i])){
                result.push_back(s[i]);
                i++;
            }else{
                i++;
                temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                i++;
                if(count.find(temp)!=count.end()){
                    result+=count[temp];
                }else{
                    result+="?";
                }
            }
        }
        return result;
    }
};