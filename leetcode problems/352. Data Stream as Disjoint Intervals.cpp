// 352. Data Stream as Disjoint Intervals


// Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

// Implement the SummaryRanges class:

// SummaryRanges() Initializes the object with an empty stream.
// void addNum(int value) Adds the integer value to the stream.
// int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.



//------------------------------------Solution--------------------------------

class SummaryRanges
{
public:
    set<int> stream;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        stream.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        int prev = -1;
        vector<vector<int>> ans;
        vector<int> temp;
        for (auto it : stream)
        {
            if (prev != -1 && it != prev + 1)
            {
                if (temp.size() == 1)
                {
                    temp.push_back(prev);
                }
                ans.push_back(temp);
                temp.clear();
                temp.push_back(it);
            }
            else if (prev == -1)
                temp.push_back(it);
            prev = it;
        }
        if (temp.size() == 1)
            temp.push_back(prev);
        if (temp.size() != 0)
            ans.push_back(temp);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */