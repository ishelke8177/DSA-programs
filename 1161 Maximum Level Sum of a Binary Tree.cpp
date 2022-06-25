class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int mxSum=INT_MIN;
        int minLvl=INT_MAX;

        while(!q.empty()){
            int size = q.size();
            int sum=0;
            int level;

            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                level = it.second;

                sum += temp->val;

                if(temp->left)
                    q.push({temp->left,level+1});

                if(temp->right)
                    q.push({temp->right,level+1});
            }

            if(sum>mxSum){
                mxSum = sum;
                minLvl = level;
            }

        }

        return minLvl;
    }
};
