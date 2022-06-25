class Solution {
public:
    int find(vector<int>& nums, int l, int h, int n){
        int mid;

        while(l<=h){
            mid = l + (h-l)/2;

            // check if last or first is peak
            if((mid==0 || nums[mid]>=nums[mid-1]) && (mid==n-1 || nums[mid]>=nums[mid+1]))
                break;

            // if left is greater than mid then search in the left half
            else if(mid>0 and nums[mid-1] > nums[mid])
                h = mid-1;

            // if right is greater than mid then search in the left half
            else
                l = mid+1;
        }

        return mid;
    }

    int findPeakElement(vector<int>& nums) {
        return find(nums,0,nums.size()-1,nums.size());
    }
};
