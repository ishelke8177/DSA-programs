class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n),sufix(n),res;

        /*prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }

        sufix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            sufix[i] = sufix[i+1]*nums[i];
        }*/

//         for(auto i:prefix)
//             cout<<i<<" ";

//         cout<<endl;

//         for(auto i:sufix)
//             cout<<i<<" ";

        for(int i=0;i<n;i++){
            if(i==0) prefix[0] = nums[0];
            if(n-i-1 == n-1) sufix[n-1] = nums[n-1];
            else{
                prefix[i] = prefix[i-1]*nums[i];
                sufix[n-i-1] = sufix[(n-i-1)+1]*nums[n-i-1];
            }
        }

        for(int i=0;i<n;i++){
            if(i==0)
                res.push_back(sufix[1]);
            else if(i==n-1)
                res.push_back(prefix[n-2]);
            else
                res.push_back(sufix[i+1] * prefix[i-1]);
        }

        return res;
    }
};
