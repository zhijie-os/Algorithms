#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        // m = the number of rows
        int m = grid.size();
        // n = the number of the columns
        int n = m ? grid[0].size():0;

        int islands = 0;

        // the direction to check neighbours
        int offsets[] = {0, 1, 0, -1, 0};


        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // if found an new island
                if(grid[i][j] == '1')
                {
                    // increase
                    islands++;
                    // unmark
                    grid[i][j] = '0';


                    // BFS 
                    queue<pair<int,int>> todo;
                    todo.push({i, j});



                    while(!todo.empty())
                    {
                        // get the front of the queue
                        pair<int, int> p = todo.front();
                        todo.pop();


                        // check four directions' neighbours
                        for(int k=0; k < 4; k++)
                        {
                            int r = p.first + offsets[k];
                            int c = p.second + offsets[k+1];

                            // if any of the number is also one
                            if( r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1')
                            {
                                // unmark them
                                grid[r][c]='0';
                                todo.push({r,c});
                            }
                        }
                    }
                }
            }
        }


        return islands;
    } 
};