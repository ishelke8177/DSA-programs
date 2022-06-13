class Solution {
public:
    /* TLE
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;

        queue<TreeNode*> qp;
        queue<TreeNode*> qq;

        qp.push(p);
        qq.push(q);

        while(!qp.empty() && !qq.empty()){
            int sizep=qp.size(), sizeq=qq.size();

            while(sizep-- && sizeq--){
                TreeNode* tempp = qp.front();
                TreeNode* tempq = qq.front();

                if(tempp->val != tempq->val)
                    return false;

                if(tempp->left) qp.push(tempp->left);
                if(tempp->left) qp.push(tempp->right);

                if(tempq->left) qq.push(tempp->left);
                if(tempq->left) qq.push(tempp->right);
            }
        }

        return true;
    }*/

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both are null
        if(p == NULL &&  q== NULL)
            return true;
        // one of the two are null
        if(p == NULL ||  q== NULL)
            return false;
        // values doesn't match
        if(p->val != q->val)
            return false;
        // call again on right and left of both
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left) ;
    }
};
