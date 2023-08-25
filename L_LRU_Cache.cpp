class LRUCache {
public:
    unordered_map<int, int> mp; // for tracking no of keys in map
    unordered_map<int, int> trackTime;
    set<pair<int, int>> trackOldest;
    int size;
    int currTime = 0;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        // if key is found return its value and update its time of use:
        if(mp.find(key) != mp.end())
        {
            int time = trackTime[key];
            // deleting old usage time values of the key:
            trackOldest.erase({time, key});

            // increasing curr time and updating key values:
            currTime++;
            trackOldest.insert({currTime, key});
            trackTime[key] = currTime;
            return mp[key];
        }

        // if key is not found:
        return -1;
    }
    
    void put(int key, int value) {
        // if key exists then update its value and time:
        if(mp.find(key) != mp.end())
        {
            // finding old usage time and updating its values
            int time = trackTime[key];
            trackOldest.erase({time, key});

            currTime++;
            trackOldest.insert({currTime, key});
            mp[key] = value;
            trackTime[key] = currTime;
        }

        // if key is not found: if size is full remove oldest used key and then add new one else add new one:
        else
        {
            // if size if full, first find least used key and delete it:
            if(mp.size() == size)
            {
                int leastUsedKey = trackOldest.begin() -> second;

                // deleting least used key:
                trackOldest.erase(trackOldest.begin());
                mp.erase(leastUsedKey);
                trackTime.erase(leastUsedKey);
            }

            // add new key:
            currTime++;
            trackOldest.insert({currTime, key});
            trackTime.insert({key, currTime});
            mp.insert({key, value});
        }
    }
};