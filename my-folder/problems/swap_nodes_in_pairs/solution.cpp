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
    ListNode* swapPairs(ListNode* head) {

        ListNode* newhead = new ListNode();
        newhead->next = head;
        ListNode *temp,*fwd;
        ListNode* ptr = newhead;
        ListNode *z,*f,*s,*t;
        z=newhead;

        //while(z)

        
        while(ptr->next!=NULL){
            if(ptr->next->next!=NULL){
                temp=ptr->next;
            fwd = ptr->next->next->next;
            ptr->next->next->next = temp;
            ptr->next=ptr->next->next;
            temp->next = fwd;
            ptr = ptr->next->next;           
            }else{
                ptr = ptr->next;
            }
            cout<<"g"<<endl;
            
        }
        return newhead->next;

    }
};