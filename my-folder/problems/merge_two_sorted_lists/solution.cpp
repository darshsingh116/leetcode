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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        ListNode* head = new ListNode();
        ListNode* ptr = head;
        int temp;

        while(ptr1!=NULL || ptr2!=NULL){
            ListNode *node = new ListNode();
            
            ptr->next = node;

            if((ptr1!=NULL) && (ptr2!=NULL)){
                if((ptr1->val) <= (ptr2->val)){
                temp = ptr1->val;
                ptr1=ptr1->next;
            }else{
                temp = ptr2->val;
                ptr2=ptr2->next;
            }
            }else{
                if(ptr1==NULL){
                    temp=ptr2->val;
                    ptr2=ptr2->next;
                }else{
                   temp = ptr1->val; 
                   ptr1=ptr1->next;

                }
            }
            cout << temp<<endl;
            node->val = temp;
            ptr = node;
            //ptr=ptr->next;
        }
        return head->next;
    }

    
};