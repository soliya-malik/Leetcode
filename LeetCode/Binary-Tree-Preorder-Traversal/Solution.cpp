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
14    vector<int> preorderTraversal(TreeNode* root) {
15        vector<int> res;
16        fun(root,res);
17        return res ;
18    }
19     void fun(TreeNode* root,vector<int>& res){
20        if(root==NULL){
21            return ;
22        }
23        res.push_back(root->val);
24        fun(root->left,res);
25        fun(root->right,res);
26    }
27};