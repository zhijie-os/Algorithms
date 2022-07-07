class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size():0;
        int islands = 0;
        int offsets[] = {0, 1, 0, -1, 0};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    island++;
                    grid[i][j] = '0';
                }
            }
        }

    } 
};