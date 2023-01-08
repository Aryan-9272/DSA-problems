//1277. Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

//-----------------------------------Solution-------------------------------------------

class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int row, int col, int len, vector<vector<vector<int>>> &dp)
    {
        if (row + len > matrix.size() || col + len > matrix[0].size())
            return 0;

        if (dp[row][col][len] != -1)
            return dp[row][col][len];

        for (int j = col; j < col + len; j++)
        {
            if (matrix[row + len - 1][j] == 0)
                return 0;
        }
        for (int i = row; i < row + len; i++)
        {
            if (matrix[i][col + len - 1] == 0)
                return 0;
        }
        return dp[row][col][len] = 1 + solve(matrix, row, col, len + 1, dp);
    }
    int countSquares(vector<vector<int>> &matrix)
    {
        int sum = 0;
        vector<vector<vector<int>>> dp(matrix.size(), vector<vector<int>>(matrix[0].size(), vector<int>(max(matrix[0].size(), matrix.size()), -1)));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                sum += solve(matrix, i, j, 1, dp);
            }
        }
        return sum;
    }
};