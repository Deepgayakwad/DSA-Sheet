class Solution {
public:

    int solve(vector<vector<int>>& grid , int row , int j1 , int j2,int n,vector<vector<vector<int>>>&dp){
          
             if(row >= grid.size()) return 0;


             if(dp[row][j1][j2] != -1) return dp[row][j1][j2];
           
             int cherry = grid[row][j1];
             if(j1 != j2){
                  
                  cherry += grid[row][j2];
             }

             int ans = 0;
             for(int val1 = -1; val1 <= 1; val1++){
                   
                    for(int val2 = -1;val2<=1; val2++){
                          
                            int newRow = row + 1;
                            int new_col1 = j1 + val1;
                            int new_col2 = j2 + val2;


                             if(new_col1 >= 0 && new_col1 <n && new_col2>=0 && new_col2 < n)
                                ans = max(ans,solve(grid,newRow,new_col1,new_col2,n,dp));
                    }
             }

             return dp[row][j1][j2] = cherry + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
         
         int m = grid.size();
         int n = grid[0].size();


         vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
          
         int ans = solve(grid,0,0,n-1,n,dp);
         return ans;
    }
};