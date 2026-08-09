class Solution {
public:
   
   int solveForAlice(vector<int>&piles,int person , int i,int m,int n,vector<vector<vector<int>>>&dp){
      
         if(i >= piles.size()) return 0;


         int stones = 0;
         int result = (person == 1)? -1:INT_MAX;

         if(dp[person][i][m] != -1) return dp[person][i][m];


         for(int x = 1;x <= min(2*m,n-i);x++){
              
                stones += piles[i+x-1];

                if(person == 1){
                      
                     result = max(result,stones+solveForAlice(piles,0,i+x,max(m,x),n,dp));

                }
                else{
                      // bob turn
                      result = min(result,0 + solveForAlice(piles,1,i+x,max(m,x),n,dp));
                }
         }

         return dp[person][i][m] = result;
   }
    int stoneGameII(vector<int>& piles) {
        
          int n = piles.size();
          vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
          int ans = solveForAlice(piles,1,0,1,n,dp);
          return ans;
    }
};