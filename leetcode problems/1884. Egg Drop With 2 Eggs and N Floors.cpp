// 1884. Egg Drop With 2 Eggs and N Floors

// You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

// In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

//------------------------------Solution------------------------------

//-------------Memoization--------------
class Solution
{
public:
    int solve(int floors, int eggs, vector<vector<int>> &dp)
    {
        if (eggs == 1)
            return floors;
        if (floors <= 1)
            return floors;
        if (dp[floors][eggs] != -1)
            return dp[floors][eggs];
        int ans = INT_MAX;
        for (int i = 1; i <= floors; i++)
        {
            ans = min(ans, 1 + max(solve(i - 1, eggs - 1, dp), solve(floors - i, eggs, dp)));
        }
        return dp[floors][eggs] = ans;
    }
    int twoEggDrop(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 2, dp);
    }
};

//----------Tabulation-------------

class Solution
{
public:
    int twoEggDrop(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = i;
        }
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[1][1] = 1;
        dp[1][2] = 1;
        for (int floor = 2; floor <= n; floor++)
        {
            int temp = INT_MAX;
            for (int f = 1; f <= floor; f++)
            {
                temp = min(temp, 1 + max(dp[f - 1][1], dp[floor - f][2]));
            }
            dp[floor][2] = temp;
        }
        return dp[n][2];
    }
};