// 1638. Count Substrings That Differ by One Character

// Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

// For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

// Return the number of substrings that satisfy the condition above.

// A substring is a contiguous sequence of characters within a string.

//------------------------------Solution-----------------------------

// Memoization

class Solution
{
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {

        if (i >= s.length() || j >= t.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, s, t, dp);

        return 0;
    }

public:
    int countSubstrings(string s, string t)
    {
        int ans = 0;
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++)
            {
                int pre = solve(i, j, s, t, dp);
                if (i + pre < s.length() && j + pre < t.length())
                {
                    if (s[i + pre] == t[j + pre])
                        continue;
                    ans++;
                    if (i + pre + 1 < s.length() && j + pre + 1 < t.length())
                        ans += solve(i + pre + 1, j + pre + 1, s, t, dp);
                }
            }
        }
        return ans;
    }
};



// Tabulation

class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int ans = 0;
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), 0));

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[0])
            {
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < t.length(); j++)
        {
            if (s[0] == t[j])
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < s.length(); i++)
        {
            for (int j = 1; j < t.length(); j++)
            {
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = t.length() - 1; j >= 0; j--)
            {
                int pre = dp[i][j];
                if (i - pre >= 0 && j - pre >= 0)
                {
                    if (s[i - pre] == t[j - pre])
                    {
                        continue;
                    }
                    ans++;
                    if (i - pre - 1 >= 0 && j - pre - 1 >= 0)
                        ans += dp[i - pre - 1][j - pre - 1];
                }
            }
        }
        return ans;
    }
};