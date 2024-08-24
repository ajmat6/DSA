class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        // using dummy node creation and in ans return head -> next:
        // ListNode* head = new ListNode(0);
        // ListNode* temp = head;
        // ListNode* first = head1; ListNode* second = head2;



        ListNode* head = nullptr;
        if(head1 -> val <= head2 -> val) head = head1;
        else head = head2;

        ListNode* temp = head;
        ListNode* first = head;
        first = first -> next;
        ListNode* second = (head == head1) ? head2 : head1;

        while(first && second) {
            if(first -> val <= second -> val) {
                temp -> next = first;
                first = first -> next;
            }
            else {
                temp -> next = second;
                second = second -> next;
            }
            temp = temp -> next;
        }

        while(first) {
            temp -> next = first;
            temp = temp -> next;
            first = first -> next;
        }

        while(second) {
            temp -> next = second;
            temp = temp -> next;
            second = second -> next;
        }

        return head -> next;
    }

    ListNode* mergeSort(ListNode* head) {
        // when there is 0 and 1 node:
        if(!head || !head -> next) return head;

        // when there are 2 nodes only then finding center will not work:
        else if(head -> next -> next == NULL) {
            if(head -> val <= head -> next -> val) return head;
            ListNode* nextt = head -> next;
            nextt -> next = head;
            head -> next = nullptr;
            return nextt;
        }

        // find the middle of linked List: it will take n / 2 time
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* midNext = slow -> next;
        slow -> next = NULL;
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(midNext);
        return merge(left, right); // n time
    }

    ListNode* sortList(ListNode* head) {
        // nlogn time and n space:
        // if(!head || !head -> next) return head;
        // vector<ListNode*> arr;
        // ListNode* temp = head;
        // while(temp) {
        //     arr.push_back(temp);
        //     temp = temp -> next;
        // }

        // sort(arr.begin(), arr.end(), [](ListNode* a, ListNode* b) {
        //     return a -> val < b -> val;
        // });

        // head = arr[0];
        // temp = head;
        // for(int i=1; i<arr.size(); i++) {
        //     temp -> next = arr[i];
        //     temp = temp -> next;
        // }
        // temp -> next = nullptr; 
        // return head;



        // using merege sort: (n + n/2)logn time and logn space for recursive depth:
        return mergeSort(head);
    }
};