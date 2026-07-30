class Solution {
public:
    int minimumPushes(string word) {
        int pushes=0;
        int n = word.size();
        for(int i=0;i<n;i++){
            if((i/8)+1==1){
                pushes++;
            }else if((i/8)+1==2){
                pushes=pushes+2;
            }else if((i/8)+1==3){
                pushes=pushes+3;
            }else{
                pushes=pushes+4;
            }
        }
        return pushes;
    }
};