// 1277. Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

//-----------------------------------Solution-------------------------------------------

// memoization

class Solution
{
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
    {

        if (row >= matrix.size() || row < 0 || col >= matrix[0].size() || col < 0)
            return 0;
        if (matrix[row][col] == 0)
            return dp[row][col] = 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int len = solve(matrix, row + 1, col + 1, dp);

        if (len == 0)
            return dp[row][col] = 1;

        for (int i = 0; i < len; i++)
        {
            if (matrix[row + 1 + i][col] == 0)
                return dp[row][col] = i + 1;

            if (matrix[row][col + 1 + i] == 0)
                return dp[row][col] = i + 1;
        }

        return dp[row][col] = 1 + len;
    }

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int sum = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                sum += solve(matrix, i, j, dp);
        }
        return sum;
    }
};

// Tabulation

class Solution
{

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int sum = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[0][j] == 1)
            {
                dp[0][j] = 1;
                sum++;
            }
        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i][0] == 1)
            {
                dp[i][0] = 1;
                sum++;
            }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else if (dp[i - 1][j - 1] == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    for (int l = 0; l < dp[i - 1][j - 1]; l++)
                    {
                        if (matrix[i - 1 - l][j] == 0)
                        {
                            dp[i][j] = l + 1;
                            break;
                        }
                        else if (matrix[i][j - 1 - l] == 0)
                        {
                            dp[i][j] = l + 1;
                            break;
                        }
                    }
                    if (dp[i][j] == 0)
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
