// 787. Cheapest Flights Within K Stops

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

//-----------------------------------------Solution---------------------------------------

class Solution
{
public:
    int solve(int level, int vertex, int k, vector<pair<int, int>> adj[], int dest, vector<vector<int>> &dp)
    {
        int ans = 10000000;
        if (level > k + 1)
        {
            return ans;
        }
        if (vertex == dest)
        {
            return 0;
        }
        if (dp[vertex][level] != -1)
            return dp[vertex][level];
        for (auto it : adj[vertex])
        {
            ans = min(ans, it.second + solve(level + 1, it.first, k, adj, dest, dp));
        }
        return dp[vertex][level] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        vector<vector<int>> dp(n, vector<int>(k + 2, -1));
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        int ans = solve(0, src, k, adj, dst, dp);
        if (ans >= 10000000)
            return -1;

        return ans;
    }
};