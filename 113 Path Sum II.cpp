class Solution {
public:
    bool getAllPaths(TreeNode* root, vector<vector<int>> &res, vector<int> &arr, int t){
        // if we reach null either on left or right side then go back
        if(!root)
            return false;

        // push the node value and decrement node value from the target
        arr.push_back(root->val);
        t -= root->val;

        // If we get t==0 then we have got the pathsum
        if(t == 0 && (!root->left) && (!root->right)){
            res.push_back(arr);
        }

        // If any of them is returning true then, return true and go back
        if(getAllPaths(root->left,res,arr,t) || getAllPaths(root->right,res,arr,t))
            return true;

        t = root->val + t;
        arr.pop_back();
        return false;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> arr;
        getAllPaths(root,res,arr,targetSum);
        return res;
    }
};
