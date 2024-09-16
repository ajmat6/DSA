class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int row = 0; int col = 0; int times = 0;
        int total = m * n;
        ListNode* temp = head;
        vector<vector<int>> ans (n, vector<int> (m, -1));
        
        while(total > 0 && temp != nullptr) {
            for(; col<m-times && temp != nullptr; col++) {
                ans[row][col] = temp -> val;
                temp = temp -> next;
            }

            row++;
            col--;

            for(; row<n-times && temp != nullptr; row++) {
                ans[row][col] = temp -> val;
                temp = temp -> next;
            }

            row--;
            col--;

            for(; col>=0+times && temp != nullptr; col--) {
                ans[row][col] = temp -> val;
                temp = temp -> next;
            }

            col++;
            row--;
            times++;

            for(; row>=0 + times && temp != nullptr; row--) {
                ans[row][col] = temp -> val;
                temp = temp -> next;
            }

            row++;
            col++;
        }

        return ans;
    }
};