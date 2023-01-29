// 877. Stone Game

// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

//--------------------------------------Solution---------------------------------------

class Solution
{
public:
    pair<int, int> maxPiles(int str, int end, vector<int> &piles, vector<int> &prefix, vector<vector<pair<int, int>>> &dp)
    {
        if (str == end)
        {
            return {piles[str], 0};
        }
        if (end - str == 1)
            return {max(piles[str], piles[end]), min(piles[str], piles[end])};
        if (dp[str][end].first != -1)
            return dp[str][end];
        int alice = max(piles[str] + maxPiles(str + 1, end, piles, prefix, dp).second,
                        piles[end] + maxPiles(str, end - 1, piles, prefix, dp).second);
        int bob = prefix[end + 1] - prefix[str] - alice;
        return dp[str][end] = {alice, bob};
    }
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> prefix(piles.size() + 1, 0);
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        prefix[1] = piles[0];
        for (int i = 1; i <= piles.size(); i++)
            prefix[i] = prefix[i - 1] + piles[i - 1];
        pair<int, int> ans = maxPiles(0, piles.size() - 1, piles, prefix, dp);
        if (ans.first > ans.second)
            return true;
        else
            return false;
    }
};