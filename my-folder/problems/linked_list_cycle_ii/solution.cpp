/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map> 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> hash;
        ListNode* fast=head;
        ListNode* slow=head;
        bool ans=false;
        while(fast!=NULL && fast->next!=NULL){  
            try{
                hash[fast] = hash[fast] +1;
                hash[fast->next] = hash[fast->next] +1;
            }catch(...){
                hash[fast] = 0;
                hash[fast->next] = 0;
            }         
            fast = fast->next->next;
            slow = slow->next;       
            if(fast==slow){
                ans = true;
                break;
            }   
        }
        if(!ans){
            return NULL;
        }
        ListNode* ptr = head;
        while(hash[ptr]<=1){
            ptr=ptr->next;           
        }
        return ptr;
        
    }
};