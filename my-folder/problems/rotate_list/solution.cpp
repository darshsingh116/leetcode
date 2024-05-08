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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=1;
        ListNode* ptr = head;
        if(ptr==NULL){
            return head;
        }
        while(ptr->next!=NULL){
            ptr=ptr->next;
            n++;
        }
        k=k%n;
        if(k!=0){
            ptr->next = head;
            ptr = head;
            for(int i=1;i<n-k;i++){
                ptr=ptr->next;
            }
            head = ptr->next;
            ptr->next = NULL;

        }

        return head;
        


    }
};