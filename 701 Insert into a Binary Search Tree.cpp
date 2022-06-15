class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *temp=new TreeNode(val);

        // base
        if(!root){
            root = new TreeNode(val);
        }
        else{
            TreeNode* ptr = root;
            while(1){
                if(val < ptr->val){ // insert into left
                    if(!ptr->left){
                        ptr->left=temp;
                        break;
                    }
                    else
                        ptr=ptr->left;
                }
                else{ // insert into right
                    if(!ptr->right){
                        ptr->right=temp;
                        break;
                    }
                    else
                        ptr=ptr->right;
                }
            }
        }

        return root;
    }
};
