class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode* temp=NULL;
            for(int i=0;i<size;i++){
                temp = q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(temp->val);
        }

        return ans;
    }
};
