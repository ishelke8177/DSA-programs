#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c)
    {
        int top = 0, bottom = 0;
        int column = mat.size()-1;
        int row = mat[0].size()-1;

        int dir = 0;
        vector<int> res;
        int i=0;

        while(){
            // left to right
            if(dir == 0){
                for(i = first; i <= row; i++){
                    res.push_back(mat[row][i]);
                }
                top++; // shift the row downside by 1
            }
            // top to bottom
            if(dir == 1){
                for(i = first; i <= row; i++){
                    res.push_back(mat[i][]);
                }
                column--;
            }
            // right to left
            if(dir == 2){

            }
            // bottom to top
            if(dir == 3){

            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r);

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
