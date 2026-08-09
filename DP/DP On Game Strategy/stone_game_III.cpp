class Solution {
public:
  
    int solveForAlice(vector<int>&stoneValue,int i , int n,int person,vector<vector<int>>&dp){
          
          if(i >= stoneValue.size()) return 0;

           if(dp[i][person] != INT_MIN) return dp[i][person];

          int stones = 0;
          int result = (person == 1) ? INT_MIN:INT_MAX;


          for(int x = 1;x <=min(3,n-i);x++){
               
                 stones += stoneValue[i+x-1];

                if(person == 1){
                      
                     result = max(result,stones+solveForAlice(stoneValue,i+x,n,0,dp));

                }
                else{
                      // bob turn
                      result = min(result,0 + solveForAlice(stoneValue,i+x,n,1,dp));
                }
          }


           return dp[i][person] = result;

    }
    string stoneGameIII(vector<int>& stoneValue) {


        //   int n = piles.size();
        //   vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        //   int ans = solveForAlice(piles,1,0,1,n,dp);
        //   return ans;
        
          
           int n = stoneValue.size();


           vector<vector<int>>dp(n+1,vector<int>(2,INT_MIN));
           int AliceScore = solveForAlice(stoneValue,0,n,1,dp);
           
           int totalScore = accumulate(stoneValue.begin(),stoneValue.end(),0);
        
           int bobScore = totalScore - AliceScore;

           if(AliceScore > bobScore) return "Alice";

           return (AliceScore == bobScore)?"Tie":"Bob";

    }
};