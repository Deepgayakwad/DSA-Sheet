class Solution {
public:
   
    // int findMinHealth(vector<vector<int>>& dungeon, int i , int j , int m , int n,vector<vector<int>>&dp){
           
    //        if(i >= m || j >= n) return INT_MAX;
    //        if(i == m-1 && j == n-1){
              
    //             if(dungeon[i][j] > 0) return 1;

    //             return abs(dungeon[i][j]) + 1;
    //        }

    //        if(dp[i][j] != -1) return dp[i][j];


    //        int right = findMinHealth(dungeon,i,j+1,m,n,dp);
    //        int down = findMinHealth(dungeon,i+1,j,m,n,dp);

    //        int result = min(right,down) - dungeon[i][j];

    //        return dp[i][j] = ((result > 0) ? result:1);
            
    // }

    int findMinHByBottom(vector<vector<int>>&dungeon){
          
           int m = dungeon.size();
           int n = dungeon[0].size();

           // step1 vector prepare karo
           vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

           // step2 base case se fill karo
           for(int i = 0;i <=n; i++){
              
                  dp[m][i] = INT_MAX;
           }

           for(int i = 0;i <= m; i++){
               
                  dp[i][n] = INT_MAX;
           }

          

           for(int i = m-1; i>=0; i--){
              
                for(int j = n-1; j >= 0;j--){
                      

                      if(i == m-1 && j == n-1){
                             
                              if(dungeon[m-1][n-1] > 0) dp[m-1][n-1] = 1;
                              else {
                                    dp[m-1][n-1] = abs(dungeon[i][j]) + 1;
                                }  

                                continue;     
                      }


                      
                    int right = dp[i][j+1];
                     int down = dp[i+1][j];

                     int result = min(right,down) - dungeon[i][j];

                     dp[i][j] = ((result > 0) ? result:1);
                    

                     
                         
                }
           }

           return dp[0][0];

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
         
         int m = dungeon.size();
         int n = dungeon[0].size();

         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        //  int minHealth = findMinHealth(dungeon,0,0,m,n,dp);
        //   return minHealth;

         int minHealth2 = findMinHByBottom(dungeon);
         return minHealth2;
        
        
    }
};