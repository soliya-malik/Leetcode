1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* searchBST(TreeNode* root, int val) {
15        TreeNode* ans = NULL;
16        fun(root,val,ans);
17        return ans ;
18    }
19    void fun(TreeNode* root, int val,TreeNode* &ans){
20        if(root== NULL){
21            return  ;
22        }
23        if(root->val == val) {
24            ans = root;
25            return  ;
26        }
27        if(root->val >val){
28            fun(root->left,val,ans);
29        }
30        else{
31            fun(root->right,val,ans);
32        }
33        return ;
34    }
35};