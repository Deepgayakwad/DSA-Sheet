class Solution {
public:
  
    int findNumOfUniquePaths(vector<vector<int>>& obstacleGrid, int i , int j,int m , int n,vector<vector<int>>&dp){
          
           if(i < 0 || i>=m || j < 0 || j >= n) return 0;
           if(obstacleGrid[i][j] == 1) return 0;
           if(i == m-1 && j == n-1) return 1;


           if(dp[i][j] != -1) return dp[i][j];
           

           int right = findNumOfUniquePaths(obstacleGrid,i,j+1,m,n,dp);
           int down = findNumOfUniquePaths(obstacleGrid,i+1,j,m,n,dp);


           return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();


        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        int ans = findNumOfUniquePaths(obstacleGrid,0,0,m,n,dp);
        return ans;
    }
};