class Solution {
public:
   
    int findLPath(vector<vector<int>>& matrix,int i , int j, int m , int n, int prevValue,int sI,int sJ, vector<vector<int>>&dp){
           
           if(i < 0 || i >=m || j < 0 || j >=n) return 0;
           if(prevValue >= matrix[i][j]) return 0;

          
          if(dp[i][j] != -1) return dp[i][j];
            
           int up = 1 + findLPath(matrix,i-1,j,m,n,matrix[i][j],sI,sJ,dp);
           int left = 1 + findLPath(matrix,i,j-1,m,n,matrix[i][j],sI,sJ,dp);
           int down = 1 + findLPath(matrix,i+1,j,m,n,matrix[i][j],sI,sJ,dp);
           int right = 1 + findLPath(matrix,i,j+1,m,n,matrix[i][j],sI,sJ,dp);

           int temp1 = max(up,left);
           int temp2 = max(down,right);

           int finalAns = max(temp1,temp2);

           return dp[i][j] = finalAns;
             
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
           int m = matrix.size();
           int n = matrix[0].size();
           
           vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
           int ans = 0;

           for(int i = 0;i < m; i++){
              
                 for(int j = 0;j < n ; j++){
                     
                      int temp = findLPath(matrix,i,j,m,n,INT_MIN,i,j,dp);
                      ans = max(ans,temp);
                 }
           }

           return ans;
    }
};