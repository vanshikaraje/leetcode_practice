class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL) {

            // check duplicate group
            if(curr->next != NULL && curr->val == curr->next->val) {
                
                int val = curr->val;

                // skip all nodes of this value
                while(curr != NULL && curr->val == val) {
                    curr = curr->next;
                }

                // connect prev to next unique node
                prev->next = curr;
            }
            else {
                // unique node → move prev
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};