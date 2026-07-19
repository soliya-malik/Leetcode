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
14    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
15        vector<vector<int>> res;
16        vector<int> diary;
17        int sum = 0 ;
18        fun(root,targetSum,res,diary,sum);
19        return res;
20    }
21    void fun(TreeNode* root, int targetSum,vector<vector<int>> &res,vector<int> &diary,int sum){
22      
23        
24        if(root== NULL){
25            return ;
26        }
27        sum  = sum + root->val;
28        diary.push_back(root->val);
29        if(root->left == NULL && root->right == NULL){
30            if(sum == targetSum){
31                res.push_back(diary);
32            }
33            diary.pop_back();
34            return;
35        }
36        fun(root->left,targetSum,res,diary,sum);
37        fun(root->right,targetSum,res,diary,sum);
38        diary.pop_back();
39
40        return ;
41    }
42
43};