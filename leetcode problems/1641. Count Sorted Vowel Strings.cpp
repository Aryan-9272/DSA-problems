// 1641. Count Sorted Vowel Strings

// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.


//------------------------------------------Solution----------------------------------------------

// Memoization

class Solution
{
    int solve(int n, int ins, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return ins + 1;
        }
        if (dp[n][ins] != -1)
            return dp[n][ins];
        int sum = 0;
        for (int i = ins; i >= 0; i--)
        {
            sum += solve(n - 1, i, dp);
        }
        return dp[n][ins] = sum;
    }

public:
    int countVowelStrings(int n)
    {

        vector<vector<int>> dp(n, vector<int>(5, -1));
        return solve(n - 1, 4, dp);
    }
};

// Tabulation

class Solution
{

public:
    int countVowelStrings(int n)
    {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[0][i] = i + 1;
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < 5; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n - 1][4];
    }
};