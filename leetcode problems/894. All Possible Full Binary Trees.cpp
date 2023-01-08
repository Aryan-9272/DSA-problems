// 894. All Possible Full Binary Trees

// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

//-----------------------------------Solution-----------------------------------------

// Memoization

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
    vector<TreeNode *> solve(int n, vector<vector<TreeNode *>> &dp)
    {
        if (n == 0)
            return {NULL};
        if (n == 1)
        {
            return {new TreeNode()};
        }
        if (dp[n][0] != NULL && dp.size() != 1)
        {
            return dp[n];
        }
        vector<TreeNode *> ans;

        for (int i = n - 2; i >= 1; i -= 2)
        {
            vector<TreeNode *> t1 = solve(i, dp);
            vector<TreeNode *> t2 = solve(n - 1 - i, dp);
            for (auto it : t1)
            {
                for (auto it2 : t2)
                {
                    TreeNode *node = new TreeNode();
                    node->left = it;
                    node->right = it2;
                    ans.push_back(node);
                }
            }
        }

        return dp[n] = ans;
    }

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<vector<TreeNode *>> dp(n + 1, {NULL});
        if (n % 2 == 0)
            return {};
        return solve(n, dp);
    }
};

// Tabulation

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<vector<TreeNode *>> dp(n + 1, {NULL});
        if (n % 2 == 0)
            return {};
        dp[1] = {new TreeNode()};
        for (int i = 3; i <= n; i += 2)
        {
            vector<TreeNode *> temp;
            for (int j = 1; j < i; j += 2)
            {

                for (auto it : dp[j])
                {
                    for (auto it2 : dp[i - 1 - j])
                    {
                        TreeNode *node = new TreeNode();
                        node->left = it;
                        node->right = it2;
                        temp.push_back(node);
                    }
                }
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};