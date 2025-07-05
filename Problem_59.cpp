class Solution {
public:
   int dr[4] = {0 , 1, 0 , -1};
   int dc[4] = {1 , 0 , -1 , 0};
   vector<vector<int>> ans;
    void solve( int sz, int n , int i, int j ){
        if(sz <= 0){
            return ;
        }
        ans[i][j] = n++;
        sz--;
        if(sz <= 0){
            return ;
        }
        for(int k = 0; k<4 ; k++){
            int temp = sz;
            if(k==3){
                temp--;
            }
            while(temp--){
                i += dr[k];
                j += dc[k];
                ans[i][j] = n++;
            }
        }
        solve(sz-1 , n , i, j+1);
    }
    vector<vector<int>> generateMatrix(int n) {
    ans.resize(n , vector<int> (n , 0));
    solve( n , 1 , 0 ,  0 );
    return ans; 
    }
};
