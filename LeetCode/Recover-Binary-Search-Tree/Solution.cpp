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
14    TreeNode* prev = NULL;
15    TreeNode* g11 = NULL;
16    TreeNode* g12 = NULL;
17    TreeNode* g21 = NULL;
18    TreeNode* g22 = NULL;
19    int galat = 0 ;
20    void recoverTree(TreeNode* root) {
21        fun(root);
22        if(galat==1){
23            swap(g11->val,g12->val);
24        }else{
25            swap(g11->val,g22->val);
26        }
27        return;
28    }
29    void fun(TreeNode* root){
30        if(root==NULL){
31            return ;
32        }
33        fun(root->left);
34        if(prev==NULL) // first element 
35        {
36            prev = root;
37        }
38        else{
39            if(root->val < prev->val){
40                if(galat == 0){
41                    g11 = prev;
42                    g12 = root;
43                    galat++;
44                }
45                else{
46                    g21 = prev;
47                    g22 = root;
48                    galat++;
49                }
50            }
51            prev = root;
52        }
53        fun(root->right);
54    }
55};