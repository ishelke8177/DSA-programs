class Solution {
public:
    /* bf: tc -> O(2**n x 2**m)
    int solve(int i, int j, string &t1, string &t2){
        // base case
        if(i<0 || j<0)
            return 0;

        // match
        if(t1[i] == t2[j])
            return 1 + solve(i-1,j-1,t1,t2);

        // not match
        return max(solve(i,j-1,t1,t2),solve(i-1,j,t1,t2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        return solve(n-1,m-1,text1,text2);
    }*/

    /* memoization
    // tc-O(N*M)
    // sc-> O(N*M)-> this is for 2d vector + O(N+M)-> this is auxiliary stack space
    int solve(int i, int j, string &t1, string &t2, vector<vector<int>> &dp){
        // base case
        if(i<0 || j<0)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // match
        if(t1[i] == t2[j])
            return dp[i][j] = 1 + solve(i-1, j-1, t1, t2, dp);

        // not match
        return dp[i][j] = max(solve(i,j-1,t1,t2,dp),solve(i-1,j,t1,t2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,text1,text2,dp);
    }*/

    /*tabulation*/
    int longestCommonSubsequence(string t1, string t2) {

        int n=t1.size();
        int m=t2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++)
            dp[i][0];

        for(int j=0;j<=n;j++)
            dp[0][j];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1] == t2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        return dp[n][m];
    }
};
