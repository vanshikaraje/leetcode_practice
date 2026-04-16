/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        int sum = 0;
        while(curr!=NULL){
            if(curr->val!=0){
                sum += curr->val;
            }
            else{
                prev->val = sum;
                prev->next = curr->next;
                prev = prev->next;
                sum = 0;
            }
            curr = curr->next;
        }
        return head;
    }
};