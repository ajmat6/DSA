class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<1000001> bit(0);
        for(auto i: nums) bit[i] = 1;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr) {
            if(bit[temp -> val]) {
                if(temp == head) {
                    head = head -> next;
                    temp -> next = nullptr;
                    delete temp;
                    temp = head;
                }
                else {
                    prev -> next = temp -> next;
                    temp -> next = nullptr;
                    delete temp;
                    temp = prev -> next;
                }
            }
            else {
                prev = temp;
                temp = temp -> next;
            }
        }

        return head;
    }
};