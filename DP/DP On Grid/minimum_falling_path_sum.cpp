class Solution {
public:
 
   int findMinSum(vector<vector<int>>& grid, int i , int j,int m ,int n,vector<vector<int>>&dp){
         
             if(i == m-1 && j==n-1) return grid[m-1][n-1];
             if(i >= m || j>=n) return INT_MAX;

            if(dp[i][j] != -1) return dp[i][j];
             

             int down = findMinSum(grid,i+1,j,m,n,dp);
             int right = findMinSum(grid,i,j+1,m,n,dp);

              int currSum = grid[i][j] + ((down == INT_MAX && right == INT_MAX) ? 0:min(down,right));

              return dp[i][j] = currSum;
   }
    int minPathSum(vector<vector<int>>& grid) {
        
          int m = grid.size();
          int n = grid[0].size();

          vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
          int ans = findMinSum(grid,0,0,m,n,dp);
          return ans;
    }
};