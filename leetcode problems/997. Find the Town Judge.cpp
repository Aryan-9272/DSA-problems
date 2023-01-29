// 997. Find the Town Judge

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.



//-------------------------------------------Solution------------------------------------

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> adj[n + 1];
        for (auto it : trust)
        {
            adj[it[0]].push_back(it[1]);
        }
        int judge = 0, pos;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() == 0)
            {
                judge++;
                pos = i;
            }
        }
        if (judge == 0 || judge > 1)
            return -1;

        for (int i = 1; i <= n; i++)
        {
            if (i != pos)
            {
                int flag = 0;
                for (auto it : adj[i])
                {
                    if (it == pos)
                        flag = 1;
                }
                if (!flag)
                    return -1;
            }
        }
        return pos;
    }
};