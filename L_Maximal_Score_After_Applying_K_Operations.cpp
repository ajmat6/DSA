class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // using priority_queue: 2klogn + nlogn time and n space:
        priority_queue<int> pq;
        for(auto i: nums) pq.push(i);

        long long score = 0;
        for(int i=0; i<k; i++) {
            int currMaxScore = pq.top();
            pq.pop();

            // if curr max score is 1, then it will only give one in next remaining iterations
            if(currMaxScore == 1) {
                score += (k - i);
                break;
            }

            score += currMaxScore;
            pq.push((currMaxScore + 2)/ 3);
        }
        return score;
    }
};