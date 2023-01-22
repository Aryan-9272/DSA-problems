// 1387. Sort Integers by The Power Value

// The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

// if x is even then x = x / 2
// if x is odd then x = 3 * x + 1
// For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

// Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

// Return the kth integer in the range [lo, hi] sorted by the power value.

// Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.

//-----------------------------------Solution---------------------------------------------------

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        vector<int> dp(hi + 1, -1);
        priority_queue<pair<int, int>> pow;
        for (int i = lo; i <= hi; i++)
        {
            int j = i;
            int steps = 0;
            if (dp[i] == -1)
            {
                while (j != 1)
                {
                    if (j % 2)
                    {
                        j = 3 * j + 1;
                    }
                    else
                    {
                        j = j / 2;
                    }
                    steps++;
                }
                dp[i] = steps;
            }
            else
                steps = dp[i];
            pow.push({steps, i});
            if (pow.size() > k)
                pow.pop();
        }

        return pow.top().second;
    }
};