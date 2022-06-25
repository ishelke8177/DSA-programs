class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int leftVal=0;

        while(!q.empty()){
            int size = q.size();
            int level;

            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                level = it.second;

                if(i==0) leftVal = temp->val;

                if(temp->left)
                    q.push({temp->left,level+1});

                if(temp->right)
                    q.push({temp->right,level+1});
            }
        }

        return leftVal;
    }
};
