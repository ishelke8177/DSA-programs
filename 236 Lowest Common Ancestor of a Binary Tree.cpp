// Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base
        if(root==NULL || root==p || root==q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        // while going back

        // if left is null then return right one
        if(left==NULL)
            return right;
        // if right is null then return left one
        else if(right==NULL)
            return left;
        // both are not null, hence we have found the result
        else
            return root;
    }
};
