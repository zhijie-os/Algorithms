// use the first cell of a row/col as flag: either clear entire row/col or not

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		bool row=false, col=false;

		for(int i=0; i<matrix.size(); i++)
		{
			for(int j=0; j<matrix[0].size(); j++)
			{
				if(matrix[i][j]==0)
				{
					// indicate the first row needs to be cleaned;
					if(i==0) row=true;
					// indicate the first col needs to be cleaned;
					if(j==0) col=true;
					// indicate this column needs to be zeroed
					matrix[0][j]=0;
					// this row needs to be zeroed
					matrix[i][0]=0;
				}
			}
		}


		for(int i=1; i<matrix.size();i++)
		{
			for(int j=1; j<matrix[0].size(); j++)
			{
				if(matrix[i][0] == 0 || matrix[0][j]==0)
					matrix[i][j]=0;
			}
		}

		// zero the first row
		if(row){
			for(int j=0; j<matrix[0].size(); j++)
				matrix[0][j] = 0;
		}


		// zero the first column
		if(col){
			for(int i=0; i < matrix.size(); i++) matrix[i][0] = 0;
		}

    }
};
