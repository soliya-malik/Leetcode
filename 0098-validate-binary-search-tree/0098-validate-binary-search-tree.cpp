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
    TreeNode* prev = NULL;
     bool ans = true;
    bool isValidBST(TreeNode* root) {
       
        fun(root,prev);
        return ans;
    }
    void fun(TreeNode* root,TreeNode* &prev){
        if(root==NULL){
            return;
        }
        fun(root->left,prev);
        if(prev==NULL){ //  first element
            prev = root;
        }
        // not first element check the conditon 
        else{
            if(root->val <= prev->val){
                ans = false;
                return ;
            }
            prev = root;
        }
        fun(root->right,prev);

    }
};