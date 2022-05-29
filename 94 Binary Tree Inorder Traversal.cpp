    vector<int> inorderTraversal(TreeNode* root) {
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
