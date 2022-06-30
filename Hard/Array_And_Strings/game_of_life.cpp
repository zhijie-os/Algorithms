

#include <vector>
#include <iostream>

using namespace std;

// time = O(m*n)

class Solution
{
public:
	void gameOfLife(vector<vector<int>> &board)
	{
		// use second least bit to store the next state

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				int liveNeighbours = live_neighbours(board, i, j);
				if (board[i][j])
				{
					if (liveNeighbours == 2 || liveNeighbours == 3)
					{
						board[i][j] += 2;
					}
				}
				else if (liveNeighbours == 3)
				{
					board[i][j] += 2;
				}
			}
		}

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				board[i][j] = board[i][j] >> 1;
			}
		}
	}

	int live_neighbours(const vector<vector<int>> &arr, int m, int n)
	{
		int liveCount = 0;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{

				if (m + i >= 0 && m + i < arr.size() && n + j >= 0 && n + j < arr[0].size() && (i != 0 || j != 0))
				{
					if (arr[m + i][n + j] & 1)
					{
						liveCount++;
					}
				}
			}
		}
		return liveCount;
	}
};

// time = O(m*n), space = O(m*n)
class Solution
{
public:
	void gameOfLife(vector<vector<int>> &board)
	{
		vector<vector<int>> copied = board;

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				int liveNeighbours = live_neighbours(copied, i, j);
				if (copied[i][j])
				{
					if (liveNeighbours < 2)
					{
						board[i][j] = 0;
					}
					else if (liveNeighbours > 3)
					{
						board[i][j] = 0;
					}
				}
				else if (liveNeighbours == 3)
				{
					board[i][j] = 1;
				}
			}
		}
	}

	int live_neighbours(const vector<vector<int>> &copied, int m, int n)
	{
		int liveCount = 0;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{

				if (m + i >= 0 && m + i < copied.size() && n + j >= 0 && n + j < copied[0].size() && (i != 0 || j != 0))
				{
					if (copied[m + i][n + j])
					{
						liveCount++;
					}
				}
			}
		}
		return liveCount;
	}
};
