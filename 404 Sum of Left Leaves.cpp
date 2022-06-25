class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left and !root->right)
            return 0;

        int sum=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left and (!temp->left->left and !temp->left->right))
                    sum += temp->left->val;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }

        }

        return sum;
    }
};
