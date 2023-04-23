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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1;
        ListNode *ptr2=l2;
        
        int len1=0,len2=0;
        while(ptr1 !=NULL){
            len1++;
            ptr1 = ptr1->next;
        }
        while(ptr2 !=NULL){
            len2++;
            ptr2 = ptr2->next;
        }
         int diff,same;
        if(len1>len2){
            diff = len1-len2;
            same = len2;
            ptr1 = l1;
            ptr2 = l2;
        }else{
            diff = len2-len1;
            same=len1;
            ptr1=l2;
            ptr2=l1;
        }
        ListNode* first = new ListNode();
        ListNode* head = first;
        int carry=0,temp;

        for(int i=0;i<same;i++){
            ListNode* node = new ListNode();
            first->next = node;

            temp = ptr1->val+ptr2->val+carry;
            if(temp>9){
                carry=1;
                temp=temp%10;
            }else{
                carry=0;
            }
            node->val = temp;
            first = node;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;           
        }
        cout<<carry;

        for(int i=0;i<diff;i++){
            ListNode* node = new ListNode();
            first->next = node;
            temp = ptr1->val+carry;
            if(temp>9){
                carry=1;
                temp=temp%10;
            }else{
                carry=0;
            }
            node->val = temp;
            first = node;
            ptr1 = ptr1->next;            
        }

        if(carry==1){
            ListNode* node = new ListNode();
            first->next = node;
            node->val=carry; 
        }

        
        


        return head->next;



    }
};