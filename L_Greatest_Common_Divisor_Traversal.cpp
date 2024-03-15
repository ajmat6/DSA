class Solution {
public:
    static const int N = 1e5 + 10;
    int isPrime[N];
    int spf[N];

    void seive() {
        isPrime[0] = isPrime[1] = false;
        for(int i=1; i<N; i++) {
            spf[i] = i;
            isPrime[i] = true;
        }

        for(int i=2; i*i<N; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<N; j+=i) {
                    if(isPrime[j]) {
                        isPrime[j] = false;
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<int> getPrimeFactors(int n) {
        unordered_map<int, int> mp;
        while(n != 1) {
            mp[spf[n]]++;
            n /= spf[n];
        }

        vector<int> ans;
        for(auto i: mp) ans.push_back(i.first);
        return ans;
    }

    class DisjointSet {
        vector<int> size;
        vector<int> parent;

        public:
        DisjointSet(int n) {
            size.resize(n + 1);
            parent.resize(n + 1);

            for(int i=0; i<=n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltPrt(int node) {
            if(node == parent[node]) return node;
            else return parent[node] = findUltPrt(parent[node]);
        }

        void UnionBySize(int u, int v) {
            int ultPrtOfU = findUltPrt(u);
            int ultPrtOfV = findUltPrt(v);

            if(ultPrtOfU == ultPrtOfV) return;

            int sizeOfPrtofU = size[ultPrtOfU];
            int sizeOfPrtofV = size[ultPrtOfV];

            if(sizeOfPrtofU >= sizeOfPrtofV) {
                parent[ultPrtOfV] = ultPrtOfU;
                size[ultPrtOfU] += size[ultPrtOfV];
            }

            else {
                parent[ultPrtOfU] = ultPrtOfV;
                size[ultPrtOfV] += size[ultPrtOfU];
            }
        }
    };

    bool canTraverseAllPairs(vector<int>& nums) {
        // find all the prime factors of elements in nums:
        seive();

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[i] = getPrimeFactors(nums[i]);  
        }

        // now for 4, 3, 12, 8: 0 -> 2, 1 -> 3, 2 -> 2, 3, and for 8 which is index 3 -> 2 are prime factors
        // do reverse mapping:
        unordered_map<int, vector<int>> rev;
        for(auto i: mp) {
            for(auto j: i.second) {
                rev[j].push_back(i.first);
            }
        }

        // now iterate over rev map and make union of common prime nos indexes:
        DisjointSet ds(nums.size() - 1);
        for(auto i: rev) {
            vector<int> temp = i.second;
            for(int j=0; j<temp.size()-1; j++) {
                ds.UnionBySize(temp[j], temp[j + 1]);
            }
        }

        int parent = ds.findUltPrt(0);
        for(int i=0; i<nums.size(); i++) {
            if(ds.findUltPrt(i) != parent) return false;
        }

        return true;
    }
};