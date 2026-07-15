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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15         if(root == NULL)
16            return {}; // you have to take care of this edge case
17        queue<TreeNode*> q;
18        q.push(root);
19        bool leftright = 1;
20        vector<vector<int>> res;
21        while(!q.empty()){
22           
23            int lsize = q.size();
24            int first = 0 ;
25            int last = lsize-1;
26            vector<int> temp(lsize) ; // donot fix the size og this temp it not permanent 
27            while(lsize--){
28                 TreeNode* t = q.front();
29                 q.pop();
30                // temp.push_back(t->val);
31                if(leftright){
32                    temp[first] = t->val;
33                    first++;
34                }
35                else{
36                    temp[last]=t->val;
37                    last--;
38                }
39                 if(t->left != NULL){
40                    q.push(t->left);
41                 }
42                 if(t->right != NULL){
43                    q.push(t->right);
44                 }
45
46            }
47            res.push_back(temp);
48            leftright = 1 - leftright;
49        }
50    return res;
51    }
52};