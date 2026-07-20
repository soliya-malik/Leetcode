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
14    unordered_map<int,int> in;
15    int idx = 0;
16    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
17        for(int i = 0 ; i < inorder.size();i++){
18            in[inorder[i]] = i ;
19        }
20        int low = 0 ;
21        int high = inorder.size()-1;
22        return fun(preorder,low,high);
23    }
24
25    TreeNode* fun(vector<int> & preorder,int low,int high){
26        if(low>high) return NULL;
27        TreeNode* node =  new TreeNode(preorder[idx]);
28        idx++;
29        int id = in[node->val];
30        node->left = fun(preorder,low,id-1);
31        node->right = fun(preorder,id+1,high);
32
33        return node;
34    }
35};