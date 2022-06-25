#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rowChecker[9][10]={0};
        int colChecker[9][10]={0};
        int gridChecker[9][10]={0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j]=='.')
                    continue;

                int num = board[i][j]-'0';
                int grid = (i/3)*3+j/3;

                // rowChecker[i][num] <-> if num is already showed up in row i
                if(rowChecker[i][num]||colChecker[j][num]||gridChecker[grid][num])
                {
                    return false;
                }
                rowChecker[i][num]=colChecker[j][num]=gridChecker[grid][num]=true;
            }
        }

        return true;
    }
};