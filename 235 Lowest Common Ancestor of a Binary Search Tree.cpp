
// Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        // Value of p
        int pVal = p->val;

        // Value of q;
        int qVal = q->val;

        // Start from the root node of the tree
        TreeNode* node = root;

        while(node != nullptr){

            // Value of current node or parent node.
            int parentVal = node->val;

            // If both p and q are lesser than parent
            if(pVal < parentVal && qVal < parentVal)
                node = node->left;
            // If both p and q are greater than parent
            else if(pVal > parentVal && qVal > parentVal)
                node = node->right;
            else
                // We have found the the LCA node.
                return node;
        }

        return nullptr;
    }
};

// Recursive
class Solution {
public:
    // tc - O(H)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        int curr = root->val;

        if((curr < p->val) && (curr < q->val))
            return lowestCommonAncestor(root->right,p,q);

        if((curr > p->val) && (curr > q->val))
            return lowestCommonAncestor(root->left,p,q);

        return root;
    }
};
