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
    bool same(TreeNode* a,TreeNode* b){
        bool left=false,right=false;
        if(a==NULL&&b!=NULL||a!=NULL&&b==NULL) return false;
        else if(a==NULL&&b==NULL) return true;
        else if(a->val==b->val){
            left = same(a->left,b->left);
            right = same(a->right,b->right);
        }
        return (left&right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        return same(p,q);
    }
};
