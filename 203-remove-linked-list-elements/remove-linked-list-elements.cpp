class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // Step 1: remove from beginning
        while(head != NULL && head->val == val) {
            head = head->next;
        }

        // Step 2: traverse rest
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            if(curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};