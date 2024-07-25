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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){return ans;}
        stack<TreeNode*> s1;
        stack<int>s2;
        TreeNode* curr,temp;
        s1.push(root);
        while(!s1.empty()){
            curr=s1.top();
            s1.pop();
            // if(curr->left == nullptr && curr->right==nullptr){
            //     ans.push_back(curr->val);
            // }
            
            if(curr->left != nullptr){
                s1.push(curr->left);
            }
            if(curr->right != nullptr){
                s1.push(curr->right);
            }
            s2.push(curr->val);

        }
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }
        return ans;
    }
};