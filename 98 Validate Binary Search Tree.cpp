class Solution {
public:
    bool check(TreeNode* root, long long X, long long Y){
        if(!root)
            return true;

        if(root->val <= X || root->val >= Y)
            return false;

        return check(root->left,X,root->val)
            && check(root->right,root->val,Y);
    }

    bool isValidBST(TreeNode* root) {
        long long left=LONG_LONG_MIN, right=LONG_LONG_MAX;
        return check(root,left,right);
    }
};
