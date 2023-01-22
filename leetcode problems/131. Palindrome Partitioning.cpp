// 131. Palindrome Partitioning

// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.


//-------------------------------------------Solution----------------------------------------
class Solution
{
public:
    int isPalindrome(int str, int end, string s, vector<vector<int>> &dp)
    {
        if (str == end)
        {
            return 1;
        }
        if (end - str == 1)
        {
            return s[str] == s[end];
        }
        if (dp[str][end] != -1)
            return dp[str][end];
        if (s[str] == s[end])
            return dp[str][end] = isPalindrome(str + 1, end - 1, s, dp);
        return dp[str][end] = 0;
    }
    vector<vector<string>> solve(int str, string s, vector<vector<int>> &dp)
    {
        if (str >= s.length())
            return {{}};
        vector<vector<string>> ans;
        for (int end = str; end < s.length(); end++)
        {
            if (isPalindrome(str, end, s, dp) == 1)
            {
                vector<vector<string>> temp = solve(end + 1, s, dp);
                string t = s.substr(str, end - str + 1);
                for (auto it : temp)
                {
                    it.insert(it.begin(), t);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solve(0, s, dp);
    }
};