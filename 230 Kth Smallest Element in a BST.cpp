class Solution {
public:
    /*
    vector<int> inOrder(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *node = root;
        vector<int> res;

        while(true)
        {
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty())
                    break;
                node = s.top();
                s.pop();
                res.push_back(node->val);
                node=node->right;
            }
        }

        return res;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        res = inOrder(root);
        return res[k-1];
    }*/

    // Inorder traversal
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> s;
        TreeNode *node = root;
        int ans=0;

        while(true)
        {
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }
            else{
                node = s.top();
                s.pop();
                k--;
                if(k==0){
                    ans = node->val;
                    break;
                }

                node=node->right;
            }
        }

        return ans;
    }
};
