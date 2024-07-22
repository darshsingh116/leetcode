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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr;
        vector<vector<int>> ans;
        if(root == nullptr){return ans;}
        int level = 0;
        q.push(root);
        int numnodes = 1;
        while(!q.empty()){
            numnodes = q.size();
            vector<int> temp;
            while(numnodes>0){
                
                curr = q.front();
                q.pop();
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
                temp.push_back(curr->val);
                numnodes--;
            }
            ans.push_back(temp);


        }
        return ans;
    }
};