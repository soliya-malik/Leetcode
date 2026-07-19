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
14    int res =0 ;
15    int diameterOfBinaryTree(TreeNode* root) {
16        int sum = 0;
17        fun(root,sum);
18        return res;
19    }
20    int fun(TreeNode* root,int sum){
21        if(root==NULL){
22            return 0;
23        }
24        int left = fun(root->left,sum);
25        int right = fun(root->right,sum);
26        sum = left+right;
27        res= max(res,sum);
28
29        return 1+max(left,right);
30    }
31};