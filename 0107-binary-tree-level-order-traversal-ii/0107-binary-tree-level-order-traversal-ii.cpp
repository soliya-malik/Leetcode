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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          
           int lsize = q.size();
            vector<int> v;
           while(lsize--){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
           }
           ans.push_back(v);
        }
        int l = 0 ;
        int r = ans.size() -1;
        while(l<r){
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
    }
};