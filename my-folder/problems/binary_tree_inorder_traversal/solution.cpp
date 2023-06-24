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

    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        
        //TreeNode* ptr = root;
        //vector<int> ans;
        // TreeNode* arr = [101];
        // int i=0;
        // while(i-0 && ptr->)
        tree(root);
        return ans;


    }

    void tree(TreeNode* ptr){
        if(ptr != NULL){
            tree(ptr->left);
            ans.push_back(ptr->val);
            tree(ptr->right);
        }
    }


};