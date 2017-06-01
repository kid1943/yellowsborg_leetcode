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
    unordered_map<int,int> m;
    bool isPalindrome(ListNode* head) {
        
        int index = 0;
        
        if(head == NULL){
            return true;
        }
        
        do{
            
            m[index] = head->val;
            head = head->next;
            index++;
       
        }
        while(head != NULL);
        
        
        
        for(int i = 0; i < index/2; i++){
            if(m[i] != m[index-1-i]){
                return false;
            }
        }
        
        return true;
    }
};