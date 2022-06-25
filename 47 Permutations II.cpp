class Solution {
public:

    void recurPermute(vector<int> &ds, vector<int> &nums, set<vector<int>> &st, int freq[]) {
        // base case
        if(ds.size()==nums.size()){
            st.insert(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            // pick non picked element
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, st, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // to store the final answer
        vector<vector<int>> ans;
        set<vector<int>> st;

        // in this data structure we will be storing one-one permutations
        vector<int> ds;

        // to know non picked elements
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
            freq[i] = 0;
        recurPermute(ds, nums, st, freq);

        // store answer in 2d vector
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};
