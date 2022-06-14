
vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root)
        return {};

    //node and line
    queue<pair<Node*,int>> q;

    // line and node
    map<int,int> m;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;

        // if its already there then it will insert or else override
        m[line] = node->val;

        // if current node's left is there
        if(node->left){
            q.push({node->left,line-1});
        }

        // if current node's right is there
        if(node->right){
            q.push({node->right,line+1});
        }
    }

    for(auto it:m){
        ans.push_back(it.second);
    }

    return ans;
}
