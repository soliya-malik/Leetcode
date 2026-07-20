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
13
14public:
15    bool isBalanced(TreeNode* root) {
16        if(root==NULL){
17            return true;
18        }
19        bool isleft = isBalanced(root->left);
20        bool isright = isBalanced(root->right);
21        bool works = abs(height(root->left)-height(root->right)) <=1 ? true : false;
22        return isleft and isright and works;
23    }
24private:
25    int height(TreeNode* root){
26        if(root==NULL){
27            return -1 ;
28        }
29        int lh = height(root->left);
30        int rh = height(root->right);
31        return 1 + max(lh,rh);
32    }    
33};