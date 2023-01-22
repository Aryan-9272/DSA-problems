// 1525. Number of Good Ways to Split a String

// You are given a string s.

// A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.

// Return the number of good splits you can make in s.

//-----------------------------Solution----------------------------

class Solution
{
public:
    int numSplits(string s)
    {
        int ans = 0;
        vector<int> dp1(26, 0);
        vector<int> dp2(26, 0);
        int sum1 = 0, sum2 = 0;
        dp1[s[0] - 'a'] = 1;
        sum1++;
        for (int i = s.length() - 1; i > 0; i--)
        {
            dp2[s[i] - 'a']++;
            if (dp2[s[i] - 'a'] == 1)
                sum2++;
        }
        if (sum1 == sum2)
            ans++;
        for (int i = 1; i < s.length() - 1; i++)
        {
            dp1[s[i] - 'a']++;
            dp2[s[i] - 'a']--;
            if (dp1[s[i] - 'a'] == 1)
                sum1++;
            if (dp2[s[i] - 'a'] == 0)
                sum2--;
            if (sum1 == sum2)
            {
                ans++;
            }
        }
        return ans;
    }
};