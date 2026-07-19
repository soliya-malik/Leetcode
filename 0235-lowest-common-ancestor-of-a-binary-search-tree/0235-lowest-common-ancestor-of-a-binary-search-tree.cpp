/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        if(p->val< q->val){
            fun(root,p,q,ans);
        }
        else{
            fun(root,q,p,ans);
        }
        return ans;
    }
    void fun(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(root == NULL){
            return ;
        }
        if(root->val ==p->val || root->val == q->val){
            ans = root;
            return;
        }
        if(root->val >q->val){
            fun(root->left,p,q,ans);
        }
        else if(root->val <p->val){
            fun(root->right,p,q,ans);
        }
        else{
            ans = root ;
            return;
        }
    }
};