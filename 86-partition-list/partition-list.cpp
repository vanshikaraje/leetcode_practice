class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* leftDummy = new ListNode(0);
        ListNode* rightDummy = new ListNode(0);

        ListNode* leftTail = leftDummy;
        ListNode* rightTail = rightDummy;

        ListNode* curr = head;

        while(curr != NULL) {
            if(curr->val < x) {
                leftTail->next = curr;
                leftTail = curr;
            } else {
                rightTail->next = curr;
                rightTail = curr;
            }
            curr = curr->next;
        }

        // important: avoid cycle
        rightTail->next = NULL;

        // connect both lists
        leftTail->next = rightDummy->next;

        return leftDummy->next;
    }
};