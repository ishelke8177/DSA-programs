class Solution {
public:
    bool checkPathSum(TreeNode* root, int t){
        // if we reach null either on left or right side then return false
        if(!root)
            return false;

        // decrement node val from t
        t -= root->val;

        // If we get t==0 then we have got the sum
        if(t == 0 && (!root->left) && (!root->right))
            return true;

        // If any of them is returning true then, return true and go back
        if(checkPathSum(root->left,t) || checkPathSum(root->right,t))
            return true;

        // If no either of the above doesnt return true then add the value of the node to the target and go back
        t = root->val + t;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = checkPathSum(root,targetSum);
        return flag;
    }
};
