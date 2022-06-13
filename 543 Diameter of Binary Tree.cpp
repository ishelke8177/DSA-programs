class Solution {
    int maxi=INT_MIN;
public:
    /* function to find height
    int maxHeight(TreeNode* node){
        if(!node) return 0;
        return 1 + max(maxHeight(node->left),maxHeight(node->right));
    }

    // O(N**2)
    int diameterOfBinaryTree(TreeNode* root) {
        //base
        if(!root)
            return 0;

        // find left and right heights
        int leftH = maxHeight(root->left);
        int rightH = maxHeight(root->right);

        maxi = max(maxi, leftH+rightH);

        // traverse the tree
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        // return the max
        return maxi;
    }*/

    int height(TreeNode* node, int &maxi){
        if(!node) return 0;

        int leftHeight = height(node->left,maxi);
        int rightHeight = height(node->right,maxi);

        maxi = max(maxi, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    // O(N), sc-O(H)
    int diameterOfBinaryTree(TreeNode* root){
        int maxi=0;
        height(root,maxi);
        return maxi;
    }
};
