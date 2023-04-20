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

    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        unsigned long long int ans=0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long int start = q.front().second;
            unsigned long long int end = q.back().second;
            if(end-start+1>ans){
                ans = end-start+1;
            }
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front().first;
                unsigned long long int idx = q.front().second;
                q.pop();
                if(temp->left!=NULL){
                    q.push({temp->left,2*idx+1});
                }
                if(temp->right!=NULL){
                    q.push({temp->right,2*idx+2});
                }
            }

        }
        return ans;
    }
};
