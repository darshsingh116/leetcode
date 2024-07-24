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
    struct CompNodes{
        bool operator()(ListNode* a,ListNode* b){
            return( a->val > b->val);
        }
    };

    void addToPq(ListNode* ptr, priority_queue<ListNode*, vector<ListNode*>, CompNodes>& pq){
        while(ptr !=nullptr){
            pq.push(ptr);
            ptr=ptr->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,CompNodes> pq;

    for(auto heads:lists){
        addToPq(heads,pq);
    }    
    // Iterate over the copy
    ListNode* ans = new ListNode();
    ListNode* ptr = ans;
    while (!pq.empty()) {
        ListNode* node = new ListNode();
        ptr->next=node;
        node->val = pq.top()->val;
        ptr=ptr->next;
        pq.pop();
    }
    return ans->next;
        
    }
};