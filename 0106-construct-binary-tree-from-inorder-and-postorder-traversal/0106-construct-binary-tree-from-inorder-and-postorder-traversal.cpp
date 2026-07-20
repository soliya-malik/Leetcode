/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int idx;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        idx = postorder.size() - 1;

        return solve(postorder, 0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& postorder, int low, int high) {

        if (low > high)
            return NULL;

        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;

        int pos = mp[root->val];

        // IMPORTANT: Right first
        root->right = solve(postorder, pos + 1, high);
        root->left = solve(postorder, low, pos - 1);

        return root;
    }
};