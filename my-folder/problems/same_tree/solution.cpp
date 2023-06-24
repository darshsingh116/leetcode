/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool ans = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        treeCheck(p,q);
        return ans;
    }
    void treeCheck(TreeNode* pptr, TreeNode* qptr){
        if(pptr == NULL && qptr == NULL){
            return;
        }else if(pptr == NULL || qptr ==NULL){
            ans = false;
            return;
        }
        treeCheck(pptr->left,qptr->left);
        if(pptr->val != qptr->val){
            ans = false;
        }
        treeCheck(pptr->right,qptr->right);

    }
};