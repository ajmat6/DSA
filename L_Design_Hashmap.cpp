class MyHashMap {
public:
    vector<list<pair<int, int>>> map;
    int size;
    MyHashMap() {
        size = 1000;
        map.resize(size);
    }

    // hash function which gives us the index where current key value pair may lie in that bucket linked list;
    int hashCode(int key)
    {
        return key % size;
    }

    // search function which return an iterator pointing to  the key:
    list<pair<int, int>> :: iterator search(int key)
    {
        // finding index where the key can lie:
        int index = hashCode(key);

        // now at 'index' finding the key in the list:
        list<pair<int, int>> :: iterator it = map[index].begin();
        while(it != map[index].end())
        {
            if(it -> first == key) return it;
            it++;
        }

        return it; // iterator pointing to the end of the map if key is not found:
    }

    
    void put(int key, int value) {
        // finding index;
        int index = hashCode(key);

        // if already there is key at that index remove it:
        remove(key);

        // now insert that key into the map:
        map[index].push_back({key, value});
    }
    
    int get(int key) {
        list<pair<int, int>> :: iterator foundOrNot = search(key);

        int index = hashCode(key); // finding index;
        if(foundOrNot != map[index].end()) return foundOrNot -> second;
        else return -1;
    }
    
    void remove(int key)
    {
        int index = hashCode(key);

        // search key at that index:
        list<pair<int, int>> :: iterator findit = search(key);

        // erase key at that index:
        if(findit != map[index].end())
        {
            map[index].erase(findit);
        }
    }
};