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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* result = new ListNode();
        ListNode* resptr = result;
        ListNode* ptr = head;
        int temp=0;
        ptr = ptr->next;

        while(ptr->next != NULL){
            if(ptr->val !=0){
                temp = temp+ptr->val;
            }else{
                cout<<"~"<<endl;
                ListNode* node = new ListNode();
                resptr->next = node;
                node->val = temp;        
                resptr = resptr->next;
                temp = 0;
            }
            ptr = ptr->next;
        }
        ListNode* node = new ListNode();
        resptr->next = node;
        node->val = temp;


        return result->next;
    }
};