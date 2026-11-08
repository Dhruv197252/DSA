class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bool can_communicate = false;
                    for(int k=0;k<n;k++){
                        if(grid[i][k]==1 && k!=j){
                            can_communicate=true;
                            break;
                        }
                    }
                    if(can_communicate){

                    }else{
                        for(int l=0;l<m;l++){
                            if(grid[l][j]==1 && l!=i){
                                can_communicate = true;
                                break;
                            }
                        }
                    }
                    if(can_communicate){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};