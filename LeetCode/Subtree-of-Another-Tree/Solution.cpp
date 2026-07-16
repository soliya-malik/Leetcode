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
14    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
15        if(root == NULL){
16            return false;
17        }
18        if(subRoot == NULL){
19            return true;
20        }
21        if(isSameTree(root,subRoot)){
22            return true;
23        }
24       return isSubtree(root->left, subRoot) ||
25       isSubtree(root->right, subRoot);
26    }
27     bool isSameTree(TreeNode* p, TreeNode* q) {
28        if(p == NULL && q == NULL){
29            return true;
30        }
31        if(p == NULL || q == NULL){
32            return false;
33        }
34        if(p->val != q->val){
35            return false;
36        }
37        bool l = isSameTree(p->left , q->left);
38        bool r = isSameTree(p->right,q->right);
39
40        if( l == true && r == true){
41            return true;
42        }
43        else{
44            return false;
45        }
46    }
47};