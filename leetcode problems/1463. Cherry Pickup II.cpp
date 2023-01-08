//1463. Cherry Pickup II

// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

//-----------------------------------Solution------------------------------------------------
// memoization

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int row, int col1, int col2, vector<vector<vector<int>>> &dp)
    {
        if (row < 0 || row >= grid.size() || col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
        {
            return 0;
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        vector<int> add = {1, 0, -1};
        int m = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m = max(m, solve(grid, row + 1, col1 + add[i], col2 + add[j], dp));
            }
        }
        if (col1 != col2)
            return dp[row][col1][col2] = m + grid[row][col1] + grid[row][col2];
        else
            return dp[row][col1][col1] = m + grid[row][col1];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size() - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));
        vector<int> add = {1, 0, -1};
        for (int j = 0; j < grid[0].size(); j++)
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (j != k)
                    dp[grid.size() - 1][j][k] = grid[grid.size() - 1][j] + grid[grid.size() - 1][k];
                else
                    dp[grid.size() - 1][j][k] = grid[grid.size() - 1][j];
            }

        for (int i = grid.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                for (int k = 0; k < grid[0].size(); k++)
                {
                    int m = -1;
                    for (auto it : add)
                    {
                        for (auto it2 : add)
                        {
                            if ((it == -1 && j == 0) || (it == 1 && j == grid[0].size() - 1) || (it2 == -1 && k == 0) || (it2 == 1 && k == grid[0].size() - 1))
                                continue;
                            m = max(m, dp[i + 1][j + it][k + it2]);
                        }
                    }
                    if (j != k)
                        dp[i][j][k] = grid[i][j] + grid[i][k] + m;
                    else
                        dp[i][j][k] = grid[i][j] + m;
                }
            }
        }
        return dp[0][0][grid[0].size() - 1];
    }
};