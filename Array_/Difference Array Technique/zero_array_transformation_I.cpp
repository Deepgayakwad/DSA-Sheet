class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
         
          int n = nums.size();
          int m = queries.size();
          vector<int>diff(n,0);

          for(int i = 0 ;i < m; i++){
              
                 
                 int l = queries[i][0];
                 int r = queries[i][1];

                 diff[l] += 1;
                 
                 if(r+1 < n){
                     
                     diff[r+1] -= 1;
                 }

                 
          }

          int cum = 0;
          for(int i = 0;i < n;i++){
              
               cum = cum + diff[i];
               diff[i] = cum;
          }

          for(int i = 0;i < n;i++){
              
               if(diff[i] < nums[i]) return false;
          }

          return true;

    }
};