class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0=0;
        int count1=0;
        int count2=0;
        int n = stones.size();

        for(int i=0;i<n;i++){
            stones[i]= stones[i]%3;
        }
        for(int i=0;i<n;i++){
            if(stones[i]==0){
                count0++;
            }else if(stones[i]==1){
                count1++;
            }else{
                count2++;
            }
        }
        if(count0 % 2==0 && count1>=1 && count2>=1){
            return true;
        }else if(count0 % 2 ==1 && abs(count1-count2)>2){
            return true;
        }else{
            return false;
        }
    }
};