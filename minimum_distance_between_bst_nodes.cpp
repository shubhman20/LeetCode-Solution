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
    int mini = INT_MAX;
    void Inorder(TreeNode* root,vector<int> &a){
        if(root==NULL) return;
        Inorder(root->left,a);
        a.push_back(root->val);
        Inorder(root->right,a);
    }

    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> a;
        Inorder(root,a);
        for(int i=0;i<a.size()-1;i++){
            mini = min(mini,min(mini,abs(a[i]-a[i+1])));
        }
        return mini;
    }
};
