class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // creating distance array(poss no b/w 0 and 9999):
        vector<int> dist (100000, INT_MAX);
        
        // initializing source (start):  each index in dist will store min steps to reach that index
        dist[start] = 0;
        
        // here queue is sufficient for storing min step element as each level will have a single step increase:
        queue<pair<int, int>> q; // <steps, no we are getting>
        q.push({0, start});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            int steps = front.first; // steps that we were needed to reach 'no'
            int no = front.second; // the 'no'
            
            if(no == end) return steps; // if no is end no, return its steps 
            
            for(int i=0; i<arr.size(); i++)
            {
                // finding nextNo that we could reach by picking any of the no from arr
                int nextNo =(no * arr[i]) % 100000;
                
                // check condition to update the distance array:
                if(dist[nextNo] > steps + 1)
                {
                    dist[nextNo] = steps + 1;
                    q.push({steps + 1, nextNo});
                }
            }
        }
        
        return -1;
    }
};
