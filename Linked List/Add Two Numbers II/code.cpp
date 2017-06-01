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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* node = new ListNode(0);
         ListNode* tmp = new ListNode(0);
         tmp->next = node;
         l1 = reverseList(l1);
         l2 = reverseList(l2);
         
         int flag = 0;
         while(l1!=NULL || l2!=NULL){
             int digit = 0;
             int result = 0;
             
             if(l1 == NULL){
                 result = 0 + l2->val;
             }else if(l2 == NULL){
                 result = 0 + l1->val;
             }else{
                 result = l1->val + l2->val;
             }
                 
             if(flag == 1){
                result = result+1;
                flag = 0;
             }
             
             if(result >= 10){
                 flag = 1;
                 digit = result - 10;
             }else{
                 digit = result;
             }
             
             if(l1!=NULL){
                  l1 = l1->next;
             }
            
            if(l2!=NULL){
                 l2 = l2->next;
             }
             
             tmp->next->next = new ListNode(0);
             tmp->next->next->val = digit;
             tmp->next = tmp->next->next;
         }
         
         if(flag == 1){
             tmp->next->next = new ListNode(0);
             tmp->next->next->val = 1;
             return reverseList(node->next);
         }
         return reverseList(node->next);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
};