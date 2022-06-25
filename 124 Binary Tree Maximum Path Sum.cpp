class Solution {
public:
    int maxPathFind(TreeNode* root, int& maxi){
        if(!root) return 0;
        int leftPathSum = max(0,maxPathFind(root->left,maxi));
        int rightPathSum = max(0,maxPathFind(root->right,maxi));

        maxi = max(maxi, leftPathSum + rightPathSum + root->val);

        return (root->val) + max(leftPathSum, rightPathSum);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;
        maxPathFind(root,maxi);
        return maxi;
    }
};
