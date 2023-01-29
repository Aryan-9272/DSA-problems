// 931. Minimum Falling Path Sum

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//---------------------------------Solution---------------------------------

// Memoization

class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
    {
        if (j >= matrix[0].size())
            return 100000;
        if (i == matrix.size() - 1)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(matrix[i][j] + solve(matrix, i + 1, j, dp), min(matrix[i][j] + solve(matrix, i + 1, j - 1, dp), matrix[i][j] + solve(matrix, i + 1, j + 1, dp)));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int j = 0; j < matrix[0].size(); j++)
            ans = min(ans, solve(matrix, 0, j, dp));
        return ans;
    }
};

// Tabulation

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        if (matrix.size() == 1)
            return matrix[0][0];
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0; j < matrix[0].size(); j++)
            dp[matrix.size() - 1][j] = matrix[matrix.size() - 1][j];

        for (int i = matrix.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
                else if (j == matrix[0].size() - 1)
                    dp[i][j] = matrix[i][j] + min(dp[i + 1][j], dp[i + 1][j - 1]);
                else
                    dp[i][j] = matrix[i][j] + min(dp[i + 1][j], min(dp[i + 1][j - 1], dp[i + 1][j + 1]));
            }
        }
        for (int j = 0; j < matrix[0].size(); j++)
            ans = min(ans, dp[0][j]);
        return ans;
    }
};
