class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> arr;
        
        // Pushing values of LL into the stack:
        while(head != NULL)
        {
            arr.push_back(head -> val);
            head = head -> next;
        }

        // Applying insertion sort on the array:
        for(int i=1; i<arr.size(); i++)
        {
            int key = arr[i];
            int j = i-1;

            while(j>=0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = key;
        }

        // Creating LinkedList:
        ListNode* newhead = NULL;

        for(int i=arr.size()-1; i>=0; i--)
        {
            ListNode* newNode = new ListNode(arr[i]);
            newNode -> next = newhead;
            newhead = newNode;
        }

        return newhead;
    }
};