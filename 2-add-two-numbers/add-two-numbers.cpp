class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        int carry = 0;
        
        // Step 2: Loop until both lists and carry are finished
        while (l1 != NULL || l2 != NULL || carry != 0) {
            
            int val1 = 0;
            int val2 = 0;
            
            // If l1 is not empty, take its value
            if (l1 != NULL) {
                val1 = l1->val;
            }
            
            // If l2 is not empty, take its value
            if (l2 != NULL) {
                val2 = l2->val;
            }
            
            int sum = val1 + val2 + carry;
            
            // Update carry
            carry = sum / 10;
            
            // Store last digit
            int digit = sum % 10;
            
            // Create new node
            current->next = new ListNode(digit);
            current = current->next;
            
            // Move l1 forward
            if (l1 != NULL) {
                l1 = l1->next;
            }
            
            // Move l2 forward
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        
        // Return answer (skip dummy)
        return dummy->next;
    }
};