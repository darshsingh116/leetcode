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
        ListNode *slow=head,*fast=head;
        stack<int> stk;
        while(fast != nullptr){
            if(fast->next == nullptr){break;}
            else if( fast->next->next== nullptr){
                stk.push(slow->val);
                break;
            }
            stk.push(slow->val);
            slow=slow->next;
            fast= fast->next->next;
        }
        slow=slow->next;
        
        bool ans = true;
        while(!stk.empty()){
            if(stk.top() != slow->val){
                return false;
            }
            stk.pop();
            slow=slow->next;
        }

        return ans;
    }
};