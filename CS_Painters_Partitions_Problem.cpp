bool check(vector<int>& boards, int k, int time) {
    int count = 1;
    int currTime = 0;
    for(int i=0; i<boards.size(); i++) {
        currTime += boards[i];
        if(currTime > time) {
            count += 1;
            currTime = boards[i];
            if(currTime > time) return false; // not able to complete single board
        }
    }

    if(count <= k) return true;
    return false;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = 1;
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(check(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}