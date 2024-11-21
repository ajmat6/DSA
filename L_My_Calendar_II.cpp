// class MyCalendarTwo {
// private: vector<pair<int, int>> single, overlap;
// public:
//     MyCalendarTwo() {}
    
//     bool book(int start, int end) {
//         // first check in double:
//         for(auto i: overlap) {
//             if(max(start, i.first) < min(end, i.second)) return false;
//         }

//         // check for first:
//         for(auto i: single) {
//             int startt = max(start, i.first);
//             int endd = min(end, i.second);
//             if(startt < endd) overlap.push_back({startt, endd}); // this time is overlapping time
//         }
//         single.push_back({start, end});
//         return true;
//     }
// };


// class MyCalendarTwo {
// private: vector<pair<int, int>> single; // binary search over single time interval will not work as current interval can overlap with all the single interval at the worst case. So you need to check for all single intervals.
//          set<pair<int, int>> overlap;
// public:
//     MyCalendarTwo() {}
    
//     bool book(int start, int end) {
//         // first check in overlap using binary search:
//         auto ptr = overlap.lower_bound({start, -1});
//         if(ptr != overlap.end() && ptr -> first < end) return false;
//         if(ptr != overlap.begin() && start < prev(ptr) -> second) return false;

//         // check for first:
//         for(auto i: single) {
//             int startt = max(start, i.first);
//             int endd = min(end, i.second);
//             if(startt < endd) overlap.insert({startt, endd}); // this time is overlapping time
//         }
//         single.push_back({start, end});
//         return true;
//     }
// };



class MyCalendarTwo {
private: map<int, int> mp;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int currStart = 0;
        for(auto i: mp) {
            currStart += i.second;
            if(currStart >= 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
            if(i.first > end) break;
        }
        return true;
    }
};


