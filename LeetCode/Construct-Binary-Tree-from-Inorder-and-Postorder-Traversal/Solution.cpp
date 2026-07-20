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
14    unordered_map<int, int> mp;
15    int idx;
16
17    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
18
19        for (int i = 0; i < inorder.size(); i++)
20            mp[inorder[i]] = i;
21
22        idx = postorder.size() - 1;
23
24        return solve(postorder, 0, inorder.size() - 1);
25    }
26
27    TreeNode* solve(vector<int>& postorder, int low, int high) {
28
29        if (low > high)
30            return NULL;
31
32        TreeNode* root = new TreeNode(postorder[idx]);
33        idx--;
34
35        int pos = mp[root->val];
36
37        // IMPORTANT: Right first
38        root->right = solve(postorder, pos + 1, high);
39        root->left = solve(postorder, low, pos - 1);
40
41        return root;
42    }
43};