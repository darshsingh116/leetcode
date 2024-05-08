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
    ListNode* reverse(ListNode* prevOfHead,int k){
        ListNode *temp,*ptr,*head,*prev,*next;
        ptr = prevOfHead->next;
        temp=ptr;
        head=ptr;
        prev=ptr;
        ptr=ptr->next;
        for(int i=1;i<k;i++){
            next = ptr->next;
            ptr->next = prev;
            prev=ptr;
            ptr=next;  //return this         
        }
        head->next = ptr;
        prevOfHead->next = prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* start = new ListNode();
        start->next = head;
        head=start;
        ptr = head;
        int i=0;
        while(ptr!=NULL){
            if(i<k){
                i++;
                ptr=ptr->next;
            }else{
                
                head = reverse(head,k);
                ptr = head;
                i=0;
            }
        }
        return start->next;
    }
};