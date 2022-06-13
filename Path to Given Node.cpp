//https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=27

bool getPath(TreeNode* root, vector<int>& arr, int x) {
    // if we reach null either on left or right side then return null
    if(!root)
        return false;

    arr.push_back(root->val);

    // we have reached the leaf
    if(root->val == x)
        return true;

    // if any of them is returning true then, return true and go back
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)){
        return true;
    }

    // if no either of the above doesnt return true then pop and return false;
    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    if(A==NULL)
        return arrr;
    getPath(A, arr, B);
    return arr;
}
