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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if(root == NULL)
            return {}; // you have to take care of this edge case
        queue<TreeNode*> q;
        q.push(root);
        bool leftright = 1;
        vector<vector<int>> res;
        while(!q.empty()){
           
            int lsize = q.size();
            int first = 0 ;
            int last = lsize-1;
            vector<int> temp(lsize) ; // donot fix the size og this temp it not permanent 
            while(lsize--){
                 TreeNode* t = q.front();
                 q.pop();
                // temp.push_back(t->val);
                if(leftright){
                    temp[first] = t->val;
                    first++;
                }
                else{
                    temp[last]=t->val;
                    last--;
                }
                 if(t->left != NULL){
                    q.push(t->left);
                 }
                 if(t->right != NULL){
                    q.push(t->right);
                 }

            }
            res.push_back(temp);
            leftright = 1 - leftright;
        }
    return res;
    }
};