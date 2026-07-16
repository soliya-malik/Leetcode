1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* ans;
13    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
14        fun(root,p,q);
15        return ans;
16    }
17    int fun(TreeNode* root, TreeNode* p, TreeNode* q){
18        if(root == NULL){
19            return 0 ;
20        }
21      int left =   fun(root->left,p,q);
22      int right = fun(root->right,p,q);
23      int self = 0 ;
24      if(root == p || root ==q){
25        self = 1 ;
26      }
27      int total = left + self + right;
28      if(total == 2 && ans == NULL){
29        ans = root;
30      }
31      return total;
32    }
33};