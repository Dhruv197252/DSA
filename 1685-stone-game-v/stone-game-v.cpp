class Solution {
public:

    int solve(int l,int r, vector<int> & cumSum, vector<vector<int>> & dp){

        if(l>=r){
            return 0;
        }

        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        int score=0;
        for(int mid=l;mid<r;mid++){
            int leftsum = cumSum[mid]-(l-1>=0? cumSum[l-1]:0);
            int rightsum = cumSum[r]-cumSum[mid];
            
            if(leftsum<rightsum){
                score=max(score,leftsum+solve(l,mid, cumSum,dp));
            }else if(rightsum<leftsum){
                score=max(score,rightsum+solve(mid+1,r, cumSum,dp));
            }else{
                score=max({score,leftsum+solve(l,mid, cumSum,dp), rightsum+solve(mid+1,r, cumSum,dp)});
            }
        }
        return dp[l][r] = score;
    }


    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> cumSum(n,0);
        cumSum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            cumSum[i] = cumSum[i-1]+stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0,n-1,cumSum, dp);
    }
};