#define vi vector<int>
vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int n = grid.size(), m = grid[0].size(), sx, sy, li = 0;
        char ch;
        map <pair <int,int>, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S')
                    sx = i, sy = j;
                if (grid[i][j] == 'L')
                    mp[{i,j}] = li++;
            }
        }

        if (li == 0) return 0;
        queue<tuple<int, int, int, int, int>> qu;
        vector<vector<vi>> dp (n, vector<vi> (m, vi((1 << li), -1)));
        qu.push({sx, sy, 0, energy, 0}); dp [sx][sy][0] = energy;

        while (!qu.empty()) {
            auto [i, j, mask, e, moves] = qu.front();
            qu.pop();

            for (int z = 0, x, y, mask_, energy_; z < 4; z++) {
                x = i + dx[z], y = j + dy[z];
                if (x < 0 || y < 0 || x == n || y == m) continue;

                ch = grid[x][y];
                if (ch == 'X') continue;
                mask_ = mask, energy_ = e - 1;
                if (ch == 'L') mask_ |= (1 << mp[{x,y}]);
                if (ch == 'R') energy_ = energy;

                if (dp[x][y][mask_] >= energy_) continue;
                if (mask_ == (1 << li) - 1) return moves + 1;
                if (energy_ == 0) continue;
                qu.push({x,y,mask_,energy_,moves+1});
                dp[x][y][mask_] = energy_;
            }
        }
        return -1;
    }
};