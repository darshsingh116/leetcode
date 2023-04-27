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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *lptr,*lp=NULL,*r,*rn;
        ListNode *ptr = new ListNode();
        ptr->next = head;
        
        for(int i=0;ptr!=NULL;i++){
            if(i==(left-1)){
                lp=ptr;
            }
            if(i==left){
                lptr = ptr;
            }
            if(i==right){
                r=ptr;
                rn=ptr->next;
                break;
            }
            ptr=ptr->next;
        }
       
        ptr = lptr;
        ListNode *next=NULL,*prev=NULL;
        while(prev!=r){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        if(left!=1){
            lp->next = r;
        }else{
            head = r;
        }
         lptr->next = rn;

        
        return head;
    }
};