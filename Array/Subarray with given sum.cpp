
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int start = 0 , end = 1;
        int curr_sum  = arr[0];
        vector<int> res;

        while(end<=n){

            if(curr_sum == s){
                res.push_back(start+1);
                res.push_back(end);
                return res;
            }
            else if(curr_sum>s){
                curr_sum -= arr[start++]; //start index will move one step forward and delete that value from current sum before moving formward
            }
            else{
                curr_sum += arr[end++];
            }
        }

        return {-1};
    }
