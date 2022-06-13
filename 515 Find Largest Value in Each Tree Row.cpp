class Solution {
public:
    // bfs, tc - O(N)
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            int maxVal=INT_MIN;

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                maxVal = max(maxVal,temp->val);

                // if left of the current node exists
                if(temp->left){
                    q.push(temp->left);
                }

                // if right of the current node exists
                if(temp->right){
                    q.push(temp->right);
                }
            }

            // push into the vector
            res.push_back(maxVal);
        }

        return res;
    }
};
