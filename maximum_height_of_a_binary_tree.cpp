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
    int dist(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(dist(root->left),dist(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return dist(root);
    }
};
