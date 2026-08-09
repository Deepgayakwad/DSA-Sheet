class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
       
        int m = bookings.size();

        vector<int>ans(n,0);

        for(int i = 0;i < m;i++){
              
              int l = bookings[i][0];
              int r = bookings[i][1];
              int x = bookings[i][2];


              ans[l-1] += x;
              if(r < n){
                  
                  ans[r] -= x;

              }
        }

        int cum = 0;

        for(int i =0;i < n; i++){
               
               cum = cum + ans[i];
               ans[i] = cum;
        }

        return ans;
    }
};