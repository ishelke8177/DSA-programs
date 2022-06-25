class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> m(numRows);

        for(int i=0;i<numRows;i++){
            m[i].resize(i+1);
            // first and last vals should be 0
            m[i][0] = 1;
            m[i][i] = 1;

            // traverse till the second last row and assign vals acrdngly
            for(int j=1;j<i;j++)
                m[i][j] = m[i-1][j-1] + m[i-1][j];
        }

        return m;
    }
};
