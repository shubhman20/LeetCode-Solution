void countGoodNodes(TreeNode*root,int maxVal){
        if(root->val>=maxVal){
            cnt++;
            maxVal=root->val;
        }
        
        if(root->left!=NULL){
            countGoodNodes(root->left,maxVal);
        }

        if(root->right!=NULL){
            countGoodNodes(root->right,maxVal);
        }
    }

    int goodNodes(TreeNode* root) {
        countGoodNodes(root,INT_MIN);
        return cnt;
    }
