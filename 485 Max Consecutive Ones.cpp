class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n=nums.size();
        int start=0, end=0;
        int count=0, maxi=0;

        while(end<n){
            if(nums[end]==1){
                count++;
                end++;
                maxi = max(maxi,count);
            }
            else{ // found 0
                start=end+1;
                end++;
                count=0;
            }
        }

        return maxi;
    }
};
