#include <numeric>

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* curr = head;

        while(curr->next != NULL) {

            int a = curr->val;
            int b = curr->next->val;

            int g = gcd(a, b);

            ListNode* newNode = new ListNode(g);

            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }
};