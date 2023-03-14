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
int num=0;
    void dfs(TreeNode *root, long long &ans , long long tmp){
        if(root->left== NULL && root->right==NULL){
            tmp = tmp*10 + root->val;
            ans+=tmp;
            return;
        }
        tmp = tmp*10 + root->val;
        if(root->left) dfs(root->left,ans,tmp);
        if(root->right) dfs(root->right,ans,tmp);
    }
    int sumNumbers(TreeNode* root) {
        long long val=0;
        dfs(root,val,0);
        return (int)val;
    }
};
