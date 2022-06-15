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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node=q.front();
            int size = q.size();
            int found=0;

            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();

                // check for the same parent
                if(temp->left && temp->right){
                    if((temp->left->val==x || temp->left->val==y) && (temp->right->val==y || temp->right->val==x))
                        return false;
                }

                if(temp->val==x || temp->val==y)
                    found++;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(found == 2)
                return true;
        }

        return false;
    }
};
