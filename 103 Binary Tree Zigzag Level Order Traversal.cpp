class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){

            int siz = q.size();
            vector<int> ds(siz);

            for(int i=0;i<siz;i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = (leftToRight) ? i:(siz-1-i);
                ds[index]=temp->val;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            leftToRight = !leftToRight;
            res.push_back(ds);
        }


        return res;
    }
};
