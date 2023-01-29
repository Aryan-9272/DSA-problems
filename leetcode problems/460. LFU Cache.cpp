//460. LFU Cache

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

//----------------------------------------Solution----------------------------------

class LFUCache
{
public:
    int size;
    int mfreq = 0;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> pos;
    LFUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        auto elem = cache.find(key);
        if (elem == cache.end())
            return -1;
        else
        {
            freq[cache[key].second].erase(pos[key]);
            cache[key].second++;
            freq[cache[key].second].push_back(key);
            pos[key] = --freq[cache[key].second].end();
            if (freq[mfreq].size() == 0)
                mfreq++;
            return cache[key].first;
        }
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            cache[key].first = value;
        }
        else
        {
            if (size == 0)
                return;
            if (cache.size() == size)
            {
                int pop_key = freq[mfreq].front();

                freq[mfreq].pop_front();
                cache.erase(pop_key);
                pos.erase(pop_key);
            }
            mfreq = 1;
            cache[key] = {value, 1};
            freq[mfreq].push_back(key);
            pos[key] = --freq[mfreq].end();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */