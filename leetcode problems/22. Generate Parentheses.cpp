// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

//--------------------------Solution---------------------------------

class Solution
{

    vector<string> solve(int n, int rem_open, int rem_close)
    {
        if (rem_open == 0)
            return {};
        if (rem_close > rem_open)
            return {};
        if (n == 0)
            return {"("};

        vector<string> prev = solve(n - 1, rem_open - 1, rem_close);

        vector<string> ans;
        for (auto it : prev)
        {
            it.push_back('(');
            ans.push_back(it);
        }
        if (rem_close == 0)
            return ans;
        prev = solve(n - 1, rem_open, rem_close - 1);
        for (auto it : prev)
        {
            it.push_back(')');
            ans.push_back(it);
        }
        return ans;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        return solve(2 * n - 1, n, n);
    }
};