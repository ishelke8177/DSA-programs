class Solution {
public:
    /* TLE
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        int minHeight = INT_MAX;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            TreeNode *temp = it.first;

            if(!temp->left && temp->right)
                minHeight = min(minHeight, it.second);

            if(temp->left)
                q.push({temp->left, it.second+1});

            if(temp->right)
                q.push({temp->right, it.second+1});
        }

        return minHeight;
    }*/

    void solve(TreeNode *root, int level, int& minH){
        if(!root)
            return;

        if(!root->left && !root->right)
            minH = min(minH, level);

        solve(root->left, level+1, minH);
        solve(root->right, level+1, minH);
    }

    int minDepth(TreeNode* root){
        if(!root) return 0;
        int minH = INT_MAX;
        solve(root, 1, minH);
        return minH;
    }
};
