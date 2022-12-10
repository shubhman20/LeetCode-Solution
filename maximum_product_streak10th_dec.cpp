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
long long ans=0;
long long sum=0;
long long mod = 1e9 + 7;
    void sumval(TreeNode* root){
        if(root==NULL)
            return;
        sum+=root->val;
        sumval(root->left);
        sumval(root->right);
    }
    int maxprod(TreeNode* root){
        long long x,y;
        if(root==NULL)
            return 0;
        x = maxprod(root->left);
        y = maxprod(root->right);
        ans = max(ans,x*(sum-x));
        ans = max(ans,y*(sum-y));
        return x+y+root->val; 
    }
    int maxProduct(TreeNode* root){
        sumval(root);
        long long t = maxprod(root);
        return ans%mod;
    }
};
