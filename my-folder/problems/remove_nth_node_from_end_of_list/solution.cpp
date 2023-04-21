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
    ListNode* removeNthFromEnd(ListNode* head, int n) {    
   
        ListNode* temp=new ListNode();
        temp->next=head;

        ListNode * ptr = temp;

        int total;
        for(total=0;ptr->next!=NULL;total++){
            ptr = ptr->next;
        }
        int start=total+1-n;
        ptr = temp;
        for(int i=0;i<start-1;i++){
            ptr = ptr->next;
        }
        ListNode* prev = ptr;
        ListNode* rem = ptr->next;  
        ptr = ptr->next;
        prev->next=ptr->next;
        delete(rem);              
        
        return temp->next;
    

    }
};