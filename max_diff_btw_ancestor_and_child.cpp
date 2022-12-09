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
    int maxdiff(TreeNode* root,int maxi,int mini){
        if(root==NULL)
            return 0;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        int a = maxdiff(root->left,maxi,mini);
        int b = maxdiff(root->right,maxi,mini);
        return max(max(a,b),maxi-mini);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN;
        int mini=INT_MAX;
        int diff=0;
        diff = maxdiff(root,maxi,mini);
        return diff;
    }
};
