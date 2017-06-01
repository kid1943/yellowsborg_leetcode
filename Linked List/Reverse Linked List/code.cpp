/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next = NULL;
        ListNode* pre = NULL;
        
        if(head == NULL){
            return NULL;
        }
        
        while(head != NULL){
          next = head->next;
          head->next = pre;
          pre = head;
          head = next;
        }
        
        return pre;
    }
};