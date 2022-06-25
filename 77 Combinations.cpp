class Solution {
public:
    void findCombinations(int ind, vector<vector<int>>& res, vector<int>& ds, int n, int k){
        // base
        if(ds.size() == k){
            res.push_back(ds);
            return;
        }

        for(int i=ind;i<=n;i++){
            if(ds.size()<=k){
                ds.push_back(i);
                findCombinations(i+1,res,ds,n,k);
                ds.pop_back();
            }
            else
                break;
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> res;
        findCombinations(1,res,ds,n,k);
        return res;
    }
};
