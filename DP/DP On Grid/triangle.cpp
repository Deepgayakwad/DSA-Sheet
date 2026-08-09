class Solution {
public:
   
    int solveByRec(vector<vector<int>>& triangle , int i , int j , int m){
           
            if(i == m-1) return triangle[i][j];



            int minSum = triangle[i][j] + min(solveByRec(triangle,i+1,j,m),solveByRec(triangle,i+1,j+1,m));

            return minSum;
    }

    int solveByMem(vector<vector<int>>& triangle , int i , int j , int m ,  vector<vector<int>>&dp){

            if(i == m-1) return triangle[i][j];

            if(dp[i][j] != INT_MAX) return dp[i][j];

            dp[i][j] = triangle[i][j] + min(solveByMem(triangle,i+1,j,m,dp),solveByMem(triangle,i+1,j+1,m,dp));

            return dp[i][j];
    }
    int solveByTab(vector<vector<int>>& triangle , int m){
           
           vector<vector<int>>dp(m,vector<int>(m,0));

           for(int col = 0 ;col < triangle[m-1].size(); col++){
               
                dp[m-1][col] = triangle[m-1][col];
           }

           for(int i_index = m-2; i_index >=0;i_index--){
                
                 for(int j_index = triangle[i_index].size()-1; j_index >=0; j_index--){
                      
                       dp[i_index][j_index] = triangle[i_index][j_index] + min(dp[i_index+1][j_index],dp[i_index+1][j_index+1]);

                 }
           }

           return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
          int m = triangle.size();
        // int ans = solveByRec(triangle,0,0,m);
        // return ans;
        
        //  vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        // int ans = solveByMem(triangle,0,0,m,dp);
        // return ans;

        int ans = solveByTab(triangle,m);
        return ans;
    }
};