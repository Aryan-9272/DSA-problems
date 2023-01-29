// 1130. Minimum Cost Tree From Leaf Values

// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

//-------------------------------------------Solution---------------------------------

class Solution
{
public:
    pair<int, int> solve(int left, int right, vector<int> &arr, vector<vector<pair<int, int>>> &dp)
    {

        if (left == right)
        {
            return {0, arr[left]};
        }

        if (dp[left][right].first != -1)
            return dp[left][right];

        int ans = INT_MAX;
        int prod;
        for (int i = left; i < right; i++)
        {
            pair<int, int> temp1 = solve(left, i, arr, dp);
            pair<int, int> temp2 = solve(i + 1, right, arr, dp);
            if (temp1.first + temp2.first + temp1.second * temp2.second < ans)
            {
                ans = temp1.first + temp2.first + temp1.second * temp2.second;
                prod = max(temp1.second, temp2.second);
            }
        }
        return dp[left][right] = {ans, prod};
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        vector<vector<pair<int, int>>> dp(arr.size(), vector<pair<int, int>>(arr.size(), {-1, -1}));
        return solve(0, arr.size() - 1, arr, dp).first;
    }
};