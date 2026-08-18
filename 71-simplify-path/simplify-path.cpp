class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        string result="";
        stringstream ss(path);
        vector<string>st;
        while(getline(ss,token,'/')){
            if(token=="" || token=="."){
                continue;
            }
            if(token!=".."){
                st.push_back(token);
            }else if(!st.empty()){
                st.pop_back();
            }

        }
        if(st.empty()){
            return "/";
        }

        for(int i=0;i<st.size();i++){
            result = result + "/" + st[i];
        }
        return result;
    }
};