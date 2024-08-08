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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        bool isleft=false;

        TreeNode *ptr=root,*prev=nullptr;
        while(ptr->val!=key){
            prev=ptr;
            if(key>ptr->val){
                ptr=ptr->right;
                isleft=false;
            }
            else{
                ptr=ptr->left;
                isleft=true;
            }
            if(ptr==nullptr){return root;}
        }

        TreeNode *newLeft,*replace=ptr;

        if(ptr->right==nullptr && ptr->left==nullptr){
            replace = nullptr;
        }else if(ptr->right==nullptr){
            replace = ptr->left;
        }else if(ptr->left==nullptr){
            replace=ptr->right;
        }else{
            newLeft=ptr->left;
            ptr=ptr->right;
            while(ptr->left!=nullptr){
                ptr=ptr->left;
            }
            ptr->left=newLeft;
            replace=replace->right;
        }

        if(prev==nullptr){
            root=replace;
        }else if(isleft){
            prev->left=replace;
        }else{
            prev->right=replace;
        }
        

        
        // delete(replace);

        return root;
    }
};