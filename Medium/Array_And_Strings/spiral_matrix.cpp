#include <vector>

using namespace std;


// I really dont understhand this code, for me it is just some "smart" code



// say if we have m*n matrix
// {n ->, n-1 <-, n-2 >- .... }
// {m-1 down, m-2 ^, m-3 down ....}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // directions vector,
        // 0: go right, col index ++
        // 1: go down, row index ++
        // 2: go left, col index --
        // 3: go up, row index --
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};

        int nr = matrix.size();
        if(nr==0)
            return {};
        
        int nc = matrix[0].size();
        if(nc==0)
            return {};

        // starts with rol
        // 0:right, 1:down, 2:left, 3:up
        int iDir = 0; // index of direction
        
        int ir = 0, ic = -1;  // initial position

        vector<int> result;
        

        vector<int> nSteps{nc,nr-1};

        // if there are still remaining elements to be enumerated
        while(nSteps[iDir%2])
        {


            // enumerate a row or col
            for(int i=0; i < nSteps[iDir%2]; ++i)
            {   // i is not used?


                ir += dirs[iDir][0]; 
                ic += dirs[iDir][1];
                // push the element to the result list
                result.push_back(matrix[ir][ic]);
            }            

            // update count down
            nSteps[iDir%2]--;
            // change direction 
            iDir = (iDir+1) % 4;
        }

        return result;
    }
};
