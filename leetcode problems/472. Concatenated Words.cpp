// 472. Concatenated Words

// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

//--------------------------------------Solution-------------------------------

class Solution
{
public:
    bool solve(vector<string> &words, string str, int n, unordered_set<string> &dict)
    {
        bool ans = 0;
        if (n > 0 && dict.find(str) != dict.end())
            return 1;
        for (int i = 1; i <= str.length(); i++)
        {
            if (dict.find(str.substr(0, i)) != dict.end())
            {
                ans = ans || solve(words, str.substr(i, str.length() - i), n + 1, dict);
            }
        }
        return ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;
        unordered_set<string> dict;
        for (auto it : words)
            dict.insert(it);
        for (auto it : words)
            if (solve(words, it, 0, dict))
                ans.push_back(it);
        return ans;
    }
};