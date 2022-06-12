#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:

    // clockwise
    void rotate(vector<vector<int>>& matrix) 
    {
       // reverse the rows
       // then symmetrically swap the elements
        reverse(matrix.begin(),matrix.end());

        int n = matrix.size();
        int temp;
        for(int i=0;i<n;i++)
        {
            // i+1, because we dont want to swap twice
            for(int j=i+1;j<n;j++)
            {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
            }
        }
    }

    // anticlockwise rotate
    // reverse the cols
    // then swap symmetrically
    void anti_rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }


        int temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};