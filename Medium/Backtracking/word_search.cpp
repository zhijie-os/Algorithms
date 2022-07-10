#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (unsigned int i = 0; i < board.size(); i++) 
            for (unsigned int j = 0; j < board[0].size(); j++) 
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }


    bool dfs(vector<vector<char>>& board, int i, int j, string& word)
    {
        // when word is empty
        if (!word.size())
            return true;

        // pruning
        if (i<0 || i>=board.size() 
                || j<0 
                || j>=board[0].size() 
                || board[i][j] != word[0])  
            return false;

        char c = board[i][j];
        board[i][j] = '*'; // mark as read

        // if match, find the subsequence
        string s = word.substr(1);

        // up, down, left, right
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        // put back the original character when it is done
        board[i][j] = c;
        return ret;
    }
};