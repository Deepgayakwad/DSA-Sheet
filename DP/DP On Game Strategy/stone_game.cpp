class Solution {
public:
  
    int solve(vector<int>&piles,int i , int j,vector<vector<int>>&dp){
          
           if(i > j) return 0;

           if(i == j) return piles[i];

           if(dp[i][j] != -1) return dp[i][j];


           int take_i = piles[i] - solve(piles,i+1,j,dp);
           int take_j = piles[j] - solve(piles,i,j-1,dp);


           return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
         

        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solve(piles,0,n-1,dp);
        
        return ans > 0;
    }
};