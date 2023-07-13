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
    bool isPalindrome(ListNode* head) {
        int stk[10*10*10*10*10];
        int i=0;
        bool ans = true;

        ListNode* ptr = head;

        while(ptr!=NULL){
            int x = ptr->val;
            stk[i++]=x;
            ptr = ptr->next;
        }

        ptr = head;
        
        while(ptr!=NULL){
            i--;
            int x = ptr->val;
            if(x!=stk[i]){
                ans = false;
            }
            ptr = ptr->next;
        }

        return ans;
    }

    

};