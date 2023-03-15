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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode *>q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(t->left!=NULL){
                if(flag==1) return false;
                q.push(t->left);
            }
            else{
                flag=1;
            }
            if(t->right!=NULL){
                if(flag==1) return false;
                q.push(t->right);

            }
            else{
                flag=1;
            }
        }
        return true;
    }
};
