class Solution {
public:
   
    int findMaxMoves(vector<vector<int>>& grid, int i , int j, int m , int n,int prevVal,vector<vector<int>>&dp){
          
            if(i < 0 || i >=m || j>= n) return 0;
            if(j > 0 && prevVal >= grid[i][j]) return 0;
              
              if(dp[i][j] != -1) return dp[i][j];


            int upRight = ((j > 0) ? 1 : 0) + findMaxMoves(grid,i-1,j+1,m,n,grid[i][j],dp);
            int Right =  ((j > 0) ? 1 : 0) + findMaxMoves(grid,i,j+1,m,n,grid[i][j],dp);
            int dRight =  ((j > 0) ? 1 : 0) + findMaxMoves(grid,i+1,j+1,m,n,grid[i][j],dp);

            
            int finalAns = max(upRight,max(Right,dRight));

            return dp[i][j] = finalAns;
            
    }
    int maxMoves(vector<vector<int>>& grid) {
        
          int ans = 0;

          int m = grid.size();
          int n = grid[0].size();

          vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

          for(int i = 0 ; i < m;i++){
               
              int temp = findMaxMoves(grid,i,0,m,n,grid[i][0],dp);

               ans = max(ans,temp);
                
          }

          return ans;
    }
};