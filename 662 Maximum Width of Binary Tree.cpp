class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // base
        if(!root) return 0;

        int ans=0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            int current_min = q.front().second;
            int leftMost, rightMost;

            for(int i=0;i<size;i++){

                long long current_id = q.front().second - current_min; // subtracted to prevent integer overflow
                TreeNode * temp = q.front().first;
                q.pop();

                if (i == 0)
                    leftMost = current_id;
                if (i == size - 1)
                    rightMost = current_id;

                if(temp->left)
                    q.push({temp->left,2*current_id+1});
                if(temp->right)
                    q.push({temp->right,2*current_id+2});

            }

            ans = max(ans, rightMost - leftMost + 1);
        }

        return ans;
    }
};
